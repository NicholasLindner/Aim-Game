#include "quickshotScoreWnd.h"
#include <iostream>

QuickshotScoreWindow::QuickshotScoreWindow(const int& time1, const int& time2,
    const int& time3, const int& time4, const int& time5) {

    this->time1 = time1;
    this->time2 = time2;
    this->time3 = time3;
    this->time4 = time4;
    this->time5 = time5;
    avgTime = (time1 + time2 + time3 + time4 + time5) / 5;
    initQuickshotScoreStuff();
    }

void QuickshotScoreWindow::initQuickshotScoreStuff() {

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

    // Set up the time 1 text
    time1Text.setFont(font);
    time1Text.setString("Time 1: " + std::to_string(time1) + "ms");
    time1Text.setCharacterSize(24);
    time1Text.setFillColor(sf::Color::Blue);
    time1Text.setPosition(300, 130);

    // Set up the time 2 text
    time2Text.setFont(font);
    time2Text.setString("Time 2: " + std::to_string(time2) + "ms");
    time2Text.setCharacterSize(24);
    time2Text.setFillColor(sf::Color::Blue);
    time2Text.setPosition(300, 180);

    // Set up the time 3 text
    time3Text.setFont(font);
    time3Text.setString("Time 3: " + std::to_string(time3) + "ms");
    time3Text.setCharacterSize(24);
    time3Text.setFillColor(sf::Color::Blue);
    time3Text.setPosition(300, 230);

    // Set up the time 4 text
    time4Text.setFont(font);
    time4Text.setString("Time 4: " + std::to_string(time4) + "ms");
    time4Text.setCharacterSize(24);
    time4Text.setFillColor(sf::Color::Blue);
    time4Text.setPosition(300, 280);

    // Set up the time 5 text
    time5Text.setFont(font);
    time5Text.setString("Time 5: " + std::to_string(time5) + "ms");
    time5Text.setCharacterSize(24);
    time5Text.setFillColor(sf::Color::Blue);
    time5Text.setPosition(300, 330);

    // Set up the average time text
    avgTimeText.setFont(font);
    avgTimeText.setString("Average Time: " + std::to_string(avgTime) + "ms");
    avgTimeText.setCharacterSize(24);
    avgTimeText.setFillColor(sf::Color::Blue);
    avgTimeText.setPosition(300, 380);

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

void QuickshotScoreWindow::draw() {

    window.draw(title);

    window.draw(homeButtonText);
    window.draw(homeButton);

    window.draw(time1Text);
    window.draw(time2Text);
    window.draw(time3Text);
    window.draw(time4Text);
    window.draw(time5Text);
    window.draw(avgTimeText);


}

void QuickshotScoreWindow::handleEvents() {

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
