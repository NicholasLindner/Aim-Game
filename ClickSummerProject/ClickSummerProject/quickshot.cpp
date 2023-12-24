#include "quickshot.h"
#include <iostream>


QuickshotWindow::QuickshotWindow() {

    initQuickshotScreen();
    initText();
    startTimer();
    waitTime = 3000;

    sf::Texture originalTexture;
    if (!originalTexture.loadFromFile(gameCrosshair)) {
        // Error loading crosshair image
    }

    sf::Cursor cursor;

    if (cursor.loadFromPixels(originalTexture.copyToImage().getPixelsPtr(), originalTexture.getSize(), { 20, 20 })) {
        window.setMouseCursor(cursor);
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

void QuickshotWindow::initText() {

    font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");

    // Set up the button 1 text
    firstTargetTime.setFont(font);
    if (clickNumber < 1) {
        firstTargetTime.setString("1: ?");
    }
    else {
        firstTargetTime.setString("1: " + std::to_string(time1) + "ms");
    }
    firstTargetTime.setCharacterSize(15);
    firstTargetTime.setFillColor(sf::Color::White);
    firstTargetTime.setPosition(10, 20);

    // Set up the button 2 text
    secondTargetTime.setFont(font);
    if (clickNumber < 2) {
        secondTargetTime.setString("2: ?");

    }
    else {
        secondTargetTime.setString("2: " + std::to_string(time2) + "ms");
    }
    secondTargetTime.setCharacterSize(15);
    secondTargetTime.setFillColor(sf::Color::White);
    secondTargetTime.setPosition(10, 50);

    // Set up the button 3 text
    thirdTargetTime.setFont(font);
    if (clickNumber < 3) {
        thirdTargetTime.setString("3: ?");
    }
    else {
        thirdTargetTime.setString("3: " + std::to_string(time3) + "ms");
    }
    thirdTargetTime.setCharacterSize(15);
    thirdTargetTime.setFillColor(sf::Color::White);
    thirdTargetTime.setPosition(10, 80);

    // Set up the button 4 text
    fourthTargetTime.setFont(font);
    if (clickNumber < 4) {
        fourthTargetTime.setString("4: ?");

    }
    else {
        fourthTargetTime.setString("4: " + std::to_string(time4) + "ms");
    }
    fourthTargetTime.setCharacterSize(15);
    fourthTargetTime.setFillColor(sf::Color::White);
    fourthTargetTime.setPosition(10, 110);

    // Set up the button 5 text
    fifthTargetTime.setFont(font);
    if (clickNumber < 5) {
        fifthTargetTime.setString("5: ?");

    }
    else {
        fifthTargetTime.setString("5: " + std::to_string(time5) + "ms");
    }
    fifthTargetTime.setCharacterSize(15);
    fifthTargetTime.setFillColor(sf::Color::White);
    fifthTargetTime.setPosition(10, 140);

    // Set up missed shots text
    missedShotsText.setFont(font);
    missedShotsText.setString("Missed Shots: " + std::to_string(missedShots));
    missedShotsText.setCharacterSize(15);
    missedShotsText.setFillColor(sf::Color::White);
    missedShotsText.setPosition(800, 10);

}


void QuickshotWindow::initQuickshotScreen() {

    // Create the window
    window.create(sf::VideoMode(1000, 800), "QUICKSHOT");

 }

void QuickshotWindow::initQuickshotTarget() {
    //srand(time(NULL));
    numTargetAppearances++;
    target.setRadius(20);
    target.setPosition((int)rand()%900, (int)rand()%700);
}

void QuickshotWindow::tempHideTarget() {
    target.setRadius(20);
    target.setPosition(10000,10000);
}

void QuickshotWindow::draw() {
    window.draw(target);
    window.draw(firstTargetTime);
    window.draw(secondTargetTime);
    window.draw(thirdTargetTime);
    window.draw(fourthTargetTime);
    window.draw(fifthTargetTime); 
    window.draw(missedShotsText);

}


void QuickshotWindow::startTimer(){
    startTime = std::chrono::high_resolution_clock::now();
}

void QuickshotWindow::resetTimer(){
    startTime = std::chrono::high_resolution_clock::now();
}
void QuickshotWindow::stopTimer(){
    stoppedSecs += getOngoingMillis();
}

int QuickshotWindow::getOngoingMillis(){
    auto delta = std::chrono::high_resolution_clock::now() - startTime;
    return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(delta).count());
}

int QuickshotWindow::getTotalMillis(){
    int total = stoppedSecs;
    if (!hasEnded() && !paused)
        total += getOngoingMillis();
    return total;
}

void QuickshotWindow::getTargetTime() {
    if (clickNumber == 1) {
        time1 = getOngoingMillis();
    }
    else if (clickNumber == 2) {
        time2 = getOngoingMillis();

    }
    else if (clickNumber == 3) {
        time3 = getOngoingMillis();

    }
    else if (clickNumber == 4) {
        time4 = getOngoingMillis();

    }
    else {
        time5 = getOngoingMillis();

    }
}


void QuickshotWindow::handleEvents() {
    srand(static_cast<unsigned int>(time(0)));

    sf::Event event;
    while (window.isOpen()) {

        std::cout << getOngoingMillis() << std::endl;
        if (clickNumber == 5) {
            window.close();
            QuickshotScoreWindow quickshotScoreWindow(time1, time2, time3, time4, time5);
            quickshotScoreWindow.handleEvents();
        }
        if (getOngoingMillis() > waitTime) {
            waitTime = 100000000000;
            initQuickshotTarget();
            resetTimer();
        }
        while (window.pollEvent(event)) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (target.getGlobalBounds().contains(mousePos)) {
                    // Button was clicked

                    clickNumber++;
                    soundHit.play();
                    getTargetTime();
                    selectedGameMode = 1;
                    tempHideTarget();
                    resetTimer();
                    //srand(time(NULL));
                    waitTime = rand() % 4000;
                }
                else {
                    missedShots++;
                    soundMiss.play();
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
        
        window.clear(sf::Color::Black);
        initText();
        draw();
        window.display();
    }
}
