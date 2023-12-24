#include "settingswnd.h"

SettingsWindow::SettingsWindow() {
    initSettingsStuff();
}

void SettingsWindow::initSettingsStuff() {

    // Create the window
    window.create(sf::VideoMode(800, 600), "Settings");

    // Load the font
    font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");

    // Set up the title text
    title.setFont(font);
    title.setString("Settings");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::Blue);
    title.setPosition(280, 50);

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

    // Set up the button 1 text
    crosshairText.setFont(font);
    crosshairText.setString("Crosshairs:");
    crosshairText.setCharacterSize(24);
    crosshairText.setFillColor(sf::Color::White);
    crosshairText.setPosition(120, 170);

    // Set up the music button text
    musicButtonText.setFont(font);
    musicButtonText.setString("Music:");
    musicButtonText.setCharacterSize(24);
    musicButtonText.setFillColor(sf::Color::White);
    musicButtonText.setPosition(120, 300);

    if(!musicOn){
        // Set up music off
        musicButtonOff.setSize(sf::Vector2f(50, 50));
        musicButtonOff.setPosition(300, 340);
        musicButtonOff.setFillColor(sf::Color::Red);
        musicButtonOff.setOutlineThickness(2);
        musicButtonOff.setOutlineColor(sf::Color::Red);

        musicOffText.setFont(font);
        musicOffText.setString("OFF");
        musicOffText.setCharacterSize(24);
        musicOffText.setFillColor(sf::Color::Black);
        musicOffText.setPosition(303, 350);

        musicButtonOn.setSize(sf::Vector2f(50, 49));
        musicButtonOn.setPosition(352, 340);
        musicButtonOn.setFillColor(sf::Color::Transparent);
        musicButtonOn.setOutlineThickness(2);
        musicButtonOn.setOutlineColor(sf::Color::Green);

        musicOnText.setFont(font);
        musicOnText.setString("ON");
        musicOnText.setCharacterSize(24);
        musicOnText.setFillColor(sf::Color::Green);
        musicOnText.setPosition(360, 350);

    }
    else {
        // Set up music on

        musicButtonOn.setSize(sf::Vector2f(50, 49));
        musicButtonOn.setPosition(352, 340);
        musicButtonOn.setFillColor(sf::Color::Green);
        musicButtonOn.setOutlineThickness(2);
        musicButtonOn.setOutlineColor(sf::Color::Green);

        musicOnText.setFont(font);
        musicOnText.setString("ON");
        musicOnText.setCharacterSize(24);
        musicOnText.setFillColor(sf::Color::Black);
        musicOnText.setPosition(360, 350);

        musicButtonOff.setSize(sf::Vector2f(50, 50));
        musicButtonOff.setPosition(300, 340);
        musicButtonOff.setFillColor(sf::Color::Transparent);
        musicButtonOff.setOutlineThickness(2);
        musicButtonOff.setOutlineColor(sf::Color::Red);

        musicOffText.setFont(font);
        musicOffText.setString("OFF");
        musicOffText.setCharacterSize(24);
        musicOffText.setFillColor(sf::Color::Red);
        musicOffText.setPosition(303, 350);


    }

    
    if (!texture1.loadFromFile("newestcrosshair.png"))
    {
        // handle error
    }

    // Configure crosshairBox2
    crosshairBox1.setSize(sf::Vector2f(50, 50));  // Set the size of the rectangle
    crosshairBox1.setPosition(300, 220);          // Set the position of the rectangle
    crosshairBox1.setOutlineThickness(2);
    crosshairBox1.setOutlineColor(sf::Color::White);
    // Set the texture
    crosshairBox1.setTexture(&texture1);



    if (!texture2.loadFromFile("csgocrosshairgreen.png"))
    {
        // handle error
    }

    // Configure crosshairBox2
    crosshairBox2.setSize(sf::Vector2f(50, 50));  // Set the size of the rectangle
    crosshairBox2.setPosition(360, 220);          // Set the position of the rectangle
    crosshairBox2.setOutlineThickness(2);
    crosshairBox2.setOutlineColor(sf::Color::White);
    // Set the texture
    crosshairBox2.setTexture(&texture2);


    if (!texture3.loadFromFile("bluetrianglecrosshair.png")){
        // handle error
    }

    // Configure crosshairBox2
    crosshairBox3.setSize(sf::Vector2f(50, 50));  // Set the size of the rectangle
    crosshairBox3.setPosition(420, 220);          // Set the position of the rectangle
    crosshairBox3.setOutlineThickness(2);
    crosshairBox3.setOutlineColor(sf::Color::White);
    // Set the texture
    crosshairBox3.setTexture(&texture3);
    
    if (gameCrosshair == "newestcrosshair.png") {
        crosshairBox1.setOutlineColor(sf::Color::Green);
    }
    if (gameCrosshair == "csgocrosshairgreen.png") {
        crosshairBox2.setOutlineColor(sf::Color::Green);
    }
    if (gameCrosshair == "bluetrianglecrosshair.png") {
        crosshairBox3.setOutlineColor(sf::Color::Green);
    }

    if (!gearsTexture.loadFromFile("gears.png"))
    {
        // Error handling if the image fails to load
        // You can display a default image or exit the program
    }

    gearsSprite.setTexture(gearsTexture);
    gearsSprite.setPosition(740, 540);
}

void SettingsWindow::draw() {

    window.draw(title);

    window.draw(crosshairText);
    window.draw(crosshairBox1);
    window.draw(crosshairBox2);
    window.draw(crosshairBox3);

    window.draw(musicButtonText);
    window.draw(musicButtonOn);
    window.draw(musicButtonOff);
    window.draw(musicOffText);
    window.draw(musicOnText);




    window.draw(homeButton);
    window.draw(homeButtonText);




    //window.draw(crosshairButtonText);
    //window.draw(settingsButton);
    //window.draw(gearsSprite);
}

void SettingsWindow::handleEvents() {

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (homeButton.getGlobalBounds().contains(mousePos)) {
                    window.close();

                    WelcomeWindow welcomeWnd;
                    welcomeWnd.handleEvents();

                }
                if (crosshairBox1.getGlobalBounds().contains(mousePos)) {
                    // Button 1 was clicked
                    crosshairBox1.setOutlineThickness(2);
                    crosshairBox1.setOutlineColor(sf::Color::Green);
                    crosshairBox2.setOutlineThickness(2);
                    crosshairBox2.setOutlineColor(sf::Color::White);
                    crosshairBox3.setOutlineThickness(2);
                    crosshairBox3.setOutlineColor(sf::Color::White);
                    gameCrosshair = "newestcrosshair.png";
                }
                if (crosshairBox2.getGlobalBounds().contains(mousePos)) {
                    // Button 2 was clicked
                    crosshairBox1.setOutlineThickness(2);
                    crosshairBox1.setOutlineColor(sf::Color::White);
                    crosshairBox2.setOutlineThickness(2);
                    crosshairBox2.setOutlineColor(sf::Color::Green);
                    crosshairBox3.setOutlineThickness(2);
                    crosshairBox3.setOutlineColor(sf::Color::White);
                    gameCrosshair = "csgocrosshairgreen.png";

                }
                if (crosshairBox3.getGlobalBounds().contains(mousePos)) {
                    // Button 3 was clicked
                    crosshairBox1.setOutlineThickness(2);
                    crosshairBox1.setOutlineColor(sf::Color::White);
                    crosshairBox2.setOutlineThickness(2);
                    crosshairBox2.setOutlineColor(sf::Color::White);
                    crosshairBox3.setOutlineThickness(2);
                    crosshairBox3.setOutlineColor(sf::Color::Green);
                    gameCrosshair = "bluetrianglecrosshair.png";

                }
                if (musicButtonOn.getGlobalBounds().contains(mousePos) && !musicOn) {
                    // Music ON button clicked and music is currently off
                    
                    musicButtonOn.setFillColor(sf::Color::Green);
                    musicButtonOff.setFillColor(sf::Color::Transparent);

                    musicOnText.setFillColor(sf::Color::Black);
                    musicOffText.setFillColor(sf::Color::Red);

                    MusicPlayer::getInstance().playMusic("DRIVE.ogg");
                    musicOn = true;
                }
                if (musicButtonOff.getGlobalBounds().contains(mousePos) && musicOn) {
                    // Music OFF button clicked and music is currently on

                    MusicPlayer::getInstance().stopMusic();

                    musicButtonOn.setFillColor(sf::Color::Transparent);
                    musicButtonOff.setFillColor(sf::Color::Red);

                    musicOnText.setFillColor(sf::Color::Green);
                    musicOffText.setFillColor(sf::Color::Black);


                    musicOn = false;
                    
                }
                
                else if (settingsButton.getGlobalBounds().contains(mousePos)) {
                    window.close();
                }
            }

        }
        window.clear(sf::Color::Black);
        draw();
        window.display();
    }
}
