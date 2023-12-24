#include "doubleshot.h"
#include <iostream>

DoubleshotWindow::DoubleshotWindow() {

    initDoubleshotScreen();
    initText();
    startTimer();
    waitTime = 1000;

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
    for (int i = 0; i < livesLeft; ++i)
    {
        sf::RectangleShape heart(sf::Vector2f(32, 32));  // adjust the size as needed
        heart.setTexture(&heartTexture);
        heart.setPosition(10 + i * 40, 50);  // 50, 50 is the position, 40 is the spacing between hearts
        hearts.push_back(heart);
    }


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
}

void DoubleshotWindow::initText() {

    font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");

    // Set up the button 1 text
    hitsText.setFont(font);
    hitsText.setString("Hits: " + std::to_string(hitTargets) + "/" + std::to_string(totalTargets));
    hitsText.setCharacterSize(15);
    hitsText.setFillColor(sf::Color::White);
    hitsText.setPosition(10, 20);
   


}
    

void DoubleshotWindow::initDoubleshotScreen() {
    // Create the window
    window.create(sf::VideoMode(1000, 800), "DOUBLESHOT");

}

void DoubleshotWindow::initDoubleshotTargets() {
    //srand(time(NULL));
    numTargetAppearances++;
    target_one.setRadius(20);
    target_one.setPosition((int)rand() % 900, (int)rand() % 700);

    numTargetAppearances++;
    target_two.setRadius(20);
    target_two.setPosition((int)rand() % 900, (int)rand() % 700);

    totalTargets += 2;

    initText();
}

void DoubleshotWindow::tempHideTarget1() {
    target_one.setRadius(16);
    target_one.setPosition(10000, 10000);
}

void DoubleshotWindow::tempHideTarget2() {
    target_two.setRadius(16);
    target_two.setPosition(10000, 10000);
}

void DoubleshotWindow::draw() {
    window.draw(target_one);
    window.draw(target_two);

    window.draw(hitsText);
    window.draw(secondTargetTime);
    window.draw(thirdTargetTime);
    window.draw(fourthTargetTime);
    window.draw(fifthTargetTime);
    window.draw(missedShotsText);
    window.draw(livesText);

    for (int i = 0; i < livesLeft; ++i)
    {
        window.draw(hearts[i]);
    }

    

}


void DoubleshotWindow::startTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}

void DoubleshotWindow::resetTimer() {
    startTime = std::chrono::high_resolution_clock::now();
}
void DoubleshotWindow::stopTimer() {
    stoppedSecs += getOngoingMillis();
}

int DoubleshotWindow::getOngoingMillis() {
    auto delta = std::chrono::high_resolution_clock::now() - startTime;
    return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(delta).count());
}

int DoubleshotWindow::getTotalMillis() {
    int total = stoppedSecs;
    if (!hasEnded() && !paused)
        total += getOngoingMillis();
    return total;
}

void DoubleshotWindow::getTargetTime() {
    if (doubleClickNumber == 1) {
        time1 = getOngoingMillis();
    }
    else if (doubleClickNumber == 2) {
        time2 = getOngoingMillis();

    }
    else if (doubleClickNumber == 3) {
        time3 = getOngoingMillis();

    }
    else if (doubleClickNumber == 4) {
        time4 = getOngoingMillis();

    }
    else {
        time5 = getOngoingMillis();

    }
}


void DoubleshotWindow::handleEvents() {
    srand(static_cast<unsigned int>(time(0)));

    sf::Event event;
    while (window.isOpen()) {

        if (livesLeft <= 0) {
            window.close();
            DoubleshotScoreWindow dblshotScoreWindow(hitTargets);
            dblshotScoreWindow.handleEvents();
        }

        std::cout << getOngoingMillis() << std::endl;
 

        if (getOngoingMillis() > waitTime && allowActivateTargets == true) {
            waitTime = 1500;
            initDoubleshotTargets();
            resetTimer();
            allowActivateTargets = false;
            allowActivateGoneSound = true;

        }
        else if (getOngoingMillis() > 1550){
            resetTimer();
            tempHideTarget1();
            tempHideTarget2();
            waitTime = 1500;
            if (allowActivateGoneSound) {
                soundGone.play();
                allowActivateGoneSound = false;
            }
            allowActivateTargets = true;
        }
        while (window.pollEvent(event)) {

            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (target_one.getGlobalBounds().contains(mousePos)) {
                    // Button was clicked
                    soundHit.play();
                    setTargetOneHit++;
                    hitTargets++;
                    tempHideTarget1();
                }
                else if (target_two.getGlobalBounds().contains(mousePos)) {
                    // Button was clicked
                    soundHit.play();
                    setTargetTwoHit++;
                    hitTargets++;
                    tempHideTarget2();
                }
                else {
                    soundMiss.play();
                }

                if (setTargetOneHit >= 1 && setTargetTwoHit >= 1) {
                    setTargetOneHit = 0;
                    setTargetTwoHit = 0;
                    doubleClickNumber++;
                    allowActivateGoneSound = false;
                    getTargetTime();
                    resetTimer();
                    waitTime = 1500;

                }
               
            }

            if (0 <= mousePos.x && mousePos.x < window.getSize().x && 0 <= mousePos.y && mousePos.y < window.getSize().y) {
                sf::Texture originalTexture;
                if (!originalTexture.loadFromFile(gameCrosshair)) {
                    // Error loading crosshair image
                }

                sf::Cursor cursor;

                if (cursor.loadFromPixels(originalTexture.copyToImage().getPixelsPtr(), originalTexture.getSize(), { 20, 20 })) {
                    window.setMouseCursor(cursor);
                }
            }

        }
        missedTargets = totalTargets - hitTargets;
        if (allowActivateTargets == true) {
            livesLeft = totalLives - missedTargets;
        }

        window.clear(sf::Color::Black);
        initText();
        draw();
        window.display();
    }
}
