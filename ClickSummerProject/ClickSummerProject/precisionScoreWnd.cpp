#include "precisionScoreWnd.h"
#include <iostream>

PrecisionScoreWindow::PrecisionScoreWindow(const int& shotsMissed, const int& shotsHit, const int& totalTime) {

    this->shotsMissed = shotsMissed;
    this->shotsHit = shotsHit;
    this->totalTime = totalTime;

   
    initPrecisionScoreStuff();
}

void PrecisionScoreWindow::initPrecisionScoreStuff() {

    // Create the window
    window.create(sf::VideoMode(800, 600), "Quickshot Score");

    // Load the font
    font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");

    // Set up the title text
    title.setFont(font);
    title.setString("Score:");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setPosition(300, 20);

    // Set up the time text
    timeText.setFont(font);
    timeText.setString("Time: " + std::to_string(totalTime) + "ms");
    timeText.setCharacterSize(24);
    timeText.setFillColor(sf::Color::Blue);
    timeText.setPosition(300, 130);

    // Set up the missed shots text
    shotsMissedText.setFont(font);
    shotsMissedText.setString("Missed Shots: " + std::to_string(shotsMissed));
    shotsMissedText.setCharacterSize(24);
    shotsMissedText.setFillColor(sf::Color::Blue);
    shotsMissedText.setPosition(300, 180);

    // Set up the hit shots text
    shotsHitText.setFont(font);
    shotsHitText.setString("Hit Shots: " + std::to_string(shotsHit));
    shotsHitText.setCharacterSize(24);
    shotsHitText.setFillColor(sf::Color::Blue);
    shotsHitText.setPosition(300, 230);


    // Set up the button text
    homeButtonText.setFont(font);
    homeButtonText.setString("  Home");
    homeButtonText.setCharacterSize(24);
    homeButtonText.setFillColor(sf::Color::White);
    homeButtonText.setPosition(330, 480);

    // Set up the button rectangle
    homeButton.setSize(sf::Vector2f(200, 50));
    homeButton.setPosition(300, 480);
    homeButton.setFillColor(sf::Color::Transparent);
    homeButton.setOutlineThickness(2);
    homeButton.setOutlineColor(sf::Color::White);

}

void PrecisionScoreWindow::draw() {

    window.draw(title);

    window.draw(homeButtonText);
    window.draw(homeButton);

    window.draw(timeText);
    window.draw(shotsMissedText);
    window.draw(shotsHitText);

}


void PrecisionScoreWindow::handleEvents() {

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (homeButton.getGlobalBounds().contains(mousePos)) {
                    // Button 1 was clicked
                    window.close();
                    WelcomeWindow welcomeWnd;
                    welcomeWnd.handleEvents();

                }

            }

        }
        window.clear(sf::Color::Black);
        draw();
        window.display();
    }
}
