#include "precision.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;

Precision::Precision()
    : x(rand() % SCREEN_WIDTH), y(rand() % SCREEN_HEIGHT), creationTime(std::chrono::steady_clock::now()) {}

bool Precision::isExpired() const {
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedSeconds = currentTime - creationTime;
    return elapsedSeconds.count() >= CIRCLE_LIFETIME;
}

int Precision::getOngoingMillis() {
    auto delta = std::chrono::high_resolution_clock::now() - creationTime;
    return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(delta).count());
}

void Precision::runPrecisionGame(int mode, int circleRadius, int newCircleInitSpeed, int circleLifetime) {
    srand(static_cast<unsigned int>(time(0)));


    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Custom Game");

    std::vector<Precision> precisions;

    std::chrono::steady_clock::time_point lastCreationTime = std::chrono::steady_clock::now();



    if (!targetMiss.loadFromFile("targetmiss.wav")) { // Load your click sound file here
        // Handle the error
    }
    soundMiss.setBuffer(targetMiss);

    if (!targetGone.loadFromFile("targetgone.wav")) { // Load your click sound file here
        // Handle the error
    }
    soundGone.setBuffer(targetGone);

    if (!targetHit.loadFromFile("targethit.wav")) { // Load your click sound file here
        // Handle the error
    }
    soundHit.setBuffer(targetHit);

    sf::Texture originalTexture;
    if (!originalTexture.loadFromFile(gameCrosshair)) {
        // Error loading crosshair image
    }

    sf::Cursor cursor;

    if (cursor.loadFromPixels(originalTexture.copyToImage().getPixelsPtr(), originalTexture.getSize(), { 20, 20 })) {
        window.setMouseCursor(cursor);
    }



    if (!heartTexture.loadFromFile("gameheart.png"))
    {
        // handle error
    }
    int numLives = 0;

    if (mode == 1) {
        numLives = 10; 
    }
    else if (mode == 2) {
        numLives = 5;
    }
    else {
        numLives = 3;
    }

    std::vector<sf::RectangleShape> hearts;
    for (int i = 0; i < numLives; ++i)
    {
        sf::RectangleShape heart(sf::Vector2f(32, 32));  // adjust the size as needed
        heart.setTexture(&heartTexture);
        heart.setPosition(10 + i * 40, 20);  // 50, 50 is the position, 40 is the spacing between hearts
        hearts.push_back(heart);
    }

    CIRCLE_RADIUS = circleRadius;
    CIRCLE_INIT_SPEED = newCircleInitSpeed;
    CIRCLE_LIFETIME = circleLifetime;


    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check if the event is a mouse button press
            if (event.type == sf::Event::MouseButtonPressed) {
                // Check if the left mouse button is pressed
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get the mouse position
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Check if the mouse click is inside any of the circles
                    auto it = std::find_if(precisions.begin(), precisions.end(),
                        [&](const Precision& precision) {
                            float dx = precision.x - mousePosition.x;
                            float dy = precision.y - mousePosition.y;
                            return std::sqrt(dx * dx + dy * dy) <= CIRCLE_RADIUS;
                        });
                    

                    // If a circle is clicked, remove it from the vector
                    if (it != precisions.end()) {
                        precisions.erase(it);
                        soundHit.play();
                        hitShots++;
                    }
                    else {
                        soundMiss.play();
                        missedShots++;
                    }
                }
            }
        }

        // Get the current time
        std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

        // Calculate the elapsed time since the last circle creation
        std::chrono::duration<double> elapsedSeconds = currentTime - lastCreationTime;

        // Check if the elapsed time is greater than or equal to given second
        if (elapsedSeconds.count() >= CIRCLE_INIT_SPEED) {
            // Create a new Precision
            Precision newPrecision;
            precisions.push_back(newPrecision);

            // Update the last creation time
            lastCreationTime = currentTime;
        }

        // Clear the window
        window.clear();

        for (int i = 0; i < numLives; ++i)
        {
            window.draw(hearts[i]);
        }

        // Draw all the precisions
        for (const auto& precision : precisions) {
            sf::CircleShape circle(CIRCLE_RADIUS);
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(precision.x - CIRCLE_RADIUS, precision.y - CIRCLE_RADIUS);
            window.draw(circle);
            if (precision.isExpired()) {
                numLives--;
            }
        }
        for (auto& precision : precisions) {
            precision.CIRCLE_LIFETIME = circleLifetime;
        }

        //set up font
        sf::Font font;
        font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");

        // Set up missed shots text
        missedShotsText.setFont(font);
        missedShotsText.setString("Missed Shots: " + std::to_string(missedShots));
        missedShotsText.setCharacterSize(15);
        missedShotsText.setFillColor(sf::Color::White);
        missedShotsText.setPosition(800, 20);
        window.draw(missedShotsText);

        // set up lives text 
        //livesText.setFont(font);
        //livesText.setString("Lives Left: " + std::to_string(numLives));
        //livesText.setCharacterSize(15);
        //livesText.setFillColor(sf::Color::White);
        //livesText.setPosition(10, 20);
        //window.draw(livesText);

        // Display the window
        window.display();

        // Remove expired precisions and subtract lives
        precisions.erase(std::remove_if(precisions.begin(), precisions.end(),
            [&](const Precision& precision) {
                if (precision.isExpired()) {
                    soundGone.play();
                    numLives--; // Subtract a life
                    return true; // Remove the expired precision
                }
                return false;
            }),
            precisions.end());

        // Check if lives are zero, end the game
        if (numLives <= 0) {
            window.close();

            PrecisionScoreWindow precisionScoreWindow(missedShots, hitShots, getOngoingMillis());
            precisionScoreWindow.handleEvents();
            // Game over
    
        }

        
    }
}
