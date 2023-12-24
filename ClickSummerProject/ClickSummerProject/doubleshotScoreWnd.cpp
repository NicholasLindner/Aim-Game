#include "doubleshotScoreWnd.h"
#include <iostream>

DoubleshotScoreWindow::DoubleshotScoreWindow(int shotsHit) {

    this->shotsHit = shotsHit;
    initDoubleshotScoreStuff();
}

void DoubleshotScoreWindow::initDoubleshotScoreStuff() {

    // Create the window
    window.create(sf::VideoMode(800, 600), "Doubleshot Score");

    // Load the font
    font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");

    // Set up the title text
    title.setFont(font);
    title.setString("Score:");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);
    title.setPosition(300, 20);

    // Set up the time 1 text
    shotsHitText.setFont(font);
    shotsHitText.setString("Shots Hit: " + std::to_string(shotsHit));
    shotsHitText.setCharacterSize(45);
    shotsHitText.setFillColor(sf::Color::Blue);
    shotsHitText.setPosition(250, 230);



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

void DoubleshotScoreWindow::draw() {

    window.draw(title);

    window.draw(homeButtonText);
    window.draw(homeButton);

    window.draw(shotsHitText);


}

void DoubleshotScoreWindow::handleEvents() {

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