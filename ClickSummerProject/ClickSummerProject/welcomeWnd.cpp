#include "welcomewnd.h"

WelcomeWindow::WelcomeWindow() {
    initWelcomeStuff();
}

void WelcomeWindow::initWelcomeStuff() {

    // Create the window
    window.create(sf::VideoMode(800, 600), "Aim Trainer");

    // Load the font
    font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");

    // Set up the title text
    title.setFont(font);
    title.setString("Aim Trainer");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::Blue);
    title.setPosition(250, 50);

    // Set up the button 1 text
    button1Text.setFont(font);
    button1Text.setString("Custom");
    button1Text.setCharacterSize(24);
    button1Text.setFillColor(sf::Color::White);
    button1Text.setPosition(355, 200);

    // Set up the button 2 text
    button2Text.setFont(font);
    button2Text.setString("Quickshot");
    button2Text.setCharacterSize(24);
    button2Text.setFillColor(sf::Color::White);
    button2Text.setPosition(335, 250);

    // Set up the button 3 text
    button3Text.setFont(font);
    button3Text.setString("Doubleshot");
    button3Text.setCharacterSize(24);
    button3Text.setFillColor(sf::Color::White);
    button3Text.setPosition(330, 300);

    // Set up the button 4 text
    button4Text.setFont(font);
    button4Text.setString("Game Mode 4");
    button4Text.setCharacterSize(24);
    button4Text.setFillColor(sf::Color::White);
    button4Text.setPosition(325, 350);

    // Set up the crosshair button text
    crosshairButtonText.setFont(font);
    crosshairButtonText.setString("Customize crosshair");
    crosshairButtonText.setCharacterSize(24);
    crosshairButtonText.setFillColor(sf::Color::White);
    crosshairButtonText.setPosition(500, 500);

    // Set up the button 1 rectangle
    button1.setSize(sf::Vector2f(200, 50));
    button1.setPosition(300, 190);
    button1.setFillColor(sf::Color::Transparent);
    button1.setOutlineThickness(2);
    button1.setOutlineColor(sf::Color::White);

    // Set up the button 2 rectangle
    button2.setSize(sf::Vector2f(200, 50));
    button2.setPosition(300, 240);
    button2.setFillColor(sf::Color::Transparent);
    button2.setOutlineThickness(2);
    button2.setOutlineColor(sf::Color::White);

    // Set up the button 3 rectangle
    button3.setSize(sf::Vector2f(200, 50));
    button3.setPosition(300, 290);
    button3.setFillColor(sf::Color::Transparent);
    button3.setOutlineThickness(2);
    button3.setOutlineColor(sf::Color::White);

    // Set up the button 4 rectangle
    button4.setSize(sf::Vector2f(200, 50));
    button4.setPosition(300, 340);
    button4.setFillColor(sf::Color::Transparent);
    button4.setOutlineThickness(2);
    button4.setOutlineColor(sf::Color::White);

    // Set up the corsshair customizer button rectangle
    settingsButton.setSize(sf::Vector2f(50, 50));
    settingsButton.setPosition(735, 535);
    settingsButton.setFillColor(sf::Color::Transparent);
    settingsButton.setOutlineThickness(2);
    settingsButton.setOutlineColor(sf::Color::White);

    if (!gearsTexture.loadFromFile("gears.png"))
    {
        // Error handling if the image fails to load
        // You can display a default image or exit the program
    }

    gearsSprite.setTexture(gearsTexture);
    gearsSprite.setPosition(740, 540);
}

void WelcomeWindow::draw() {

    window.draw(title);

    window.draw(button1Text);
    window.draw(button1);

    window.draw(button2Text);
    window.draw(button2);

    window.draw(button3);
    window.draw(button3Text);

    window.draw(button4Text);
    window.draw(button4);

    //window.draw(crosshairButtonText);
    window.draw(settingsButton);
    window.draw(gearsSprite);
}

void WelcomeWindow::handleEvents() {
    
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button1.getGlobalBounds().contains(mousePos)) {
                    // Button 1 was clicked
                    //selectedGameMode = 1;
                    window.close();

                    PrecisionCustomizationWindow precisionCustomizer;
                    precisionCustomizer.runCustomizationWindow();
                    /*Precision precisionWnd;
                    precisionWnd.runPrecisionGame();*/
                    
                }
                if (button2.getGlobalBounds().contains(mousePos)) {
                    // Button 1 was clicked
                    //selectedGameMode = 1;
                    window.close();

                    QuickshotWindow quickshotWnd;
                    quickshotWnd.handleEvents();
                    /*Precision precisionWnd;
                    precisionWnd.runPrecisionGame();*/

                }
                if (button3.getGlobalBounds().contains(mousePos)) {
                    // Button 1 was clicked
                    //selectedGameMode = 1;
                    window.close();

                    DoubleshotWindow doubleshotWnd;
                    doubleshotWnd.handleEvents();
                    /*Precision precisionWnd;
                    precisionWnd.runPrecisionGame();*/
                }
                if (button4.getGlobalBounds().contains(mousePos)) {
                    window.close();
                    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "Target Game");
                    ZoomWindow zoomGame(800, 600); // initialize game class
                }
                else if (settingsButton.getGlobalBounds().contains(mousePos)) {
                    window.close();
                    SettingsWindow settingsWnd;
                    settingsWnd.handleEvents();
                }
            }
            
        }
        window.clear(sf::Color::Black);
        draw();
        window.display();
    }
}
