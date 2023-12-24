#include "PrecisionCustomizerWnd.h"
#include <iostream>

void PrecisionCustomizationWindow::runCustomizationWindow() {
    window.create(sf::VideoMode(800, 600), "Customization Window");

    font.loadFromFile("C:/Users/nicho/source/repos/ClickSummerProject/ClickSummerProject/font.ttf");


    modeText.setFont(font);
    modeText.setCharacterSize(24);
    modeText.setString("Game Mode:");
    modeText.setPosition(75, 100);

    modeValText.setFont(font);
    modeValText.setCharacterSize(24);
    modeValText.setString("Easy");
    modeValText.setPosition(225, 100);
    modeValText.setFillColor(sf::Color::Green);

    radiusText.setFont(font);
    radiusText.setCharacterSize(24);
    radiusText.setString("Target Radius:");
    radiusText.setPosition(75, 200);

    radiusValText.setFont(font);
    radiusValText.setCharacterSize(24);
    radiusValText.setString("1");
    radiusValText.setPosition(280, 200);
    radiusValText.setFillColor(sf::Color::Blue);

    speedText.setFont(font);
    speedText.setCharacterSize(24);
    speedText.setString("Appearance Speed:");
    speedText.setPosition(75, 300);

    speedValText.setFont(font);
    speedValText.setCharacterSize(24);
    speedValText.setString("1");
    speedValText.setPosition(320, 300);
    speedValText.setFillColor(sf::Color::Blue);

    lifetimeText.setFont(font);
    lifetimeText.setCharacterSize(24);
    lifetimeText.setString("Target Lifetime:");
    lifetimeText.setPosition(75, 400);

    lifetimeValText.setFont(font);
    lifetimeValText.setCharacterSize(24);
    lifetimeValText.setString("1");
    lifetimeValText.setPosition(305, 400);
    lifetimeValText.setFillColor(sf::Color::Blue);


    modeSlider.setSize(sf::Vector2f(300, 10));
    modeSlider.setPosition(400, 100);
    modeSlider.setFillColor(sf::Color::Green);

    radiusSlider.setSize(sf::Vector2f(300, 10));
    radiusSlider.setPosition(400, 200);
    radiusSlider.setFillColor(sf::Color::Green);

    speedSlider.setSize(sf::Vector2f(300, 10));
    speedSlider.setPosition(400, 300);
    speedSlider.setFillColor(sf::Color::Green);

    lifetimeSlider.setSize(sf::Vector2f(300, 10));
    lifetimeSlider.setPosition(400, 400);
    lifetimeSlider.setFillColor(sf::Color::Green);

    modeHandle.setSize(sf::Vector2f(20, 30));
    modeHandle.setPosition(400, 100);;
    modeHandle.setFillColor(sf::Color::Blue);

    radiusHandle.setSize(sf::Vector2f(20, 30));
    radiusHandle.setPosition(400, 200);
    radiusHandle.setFillColor(sf::Color::Blue);

    speedHandle.setSize(sf::Vector2f(20, 30));
    speedHandle.setPosition(400, 300);
    speedHandle.setFillColor(sf::Color::Blue);

    lifetimeHandle.setSize(sf::Vector2f(20, 30));
    lifetimeHandle.setPosition(400, 400);
    lifetimeHandle.setFillColor(sf::Color::Blue);


    startText.setFont(font);
    startText.setCharacterSize(24);
    startText.setString("Start Game");
    startText.setPosition(330, 510);
    startText.setFillColor(sf::Color::Blue);

    startButton.setSize(sf::Vector2f(200, 50));
    startButton.setPosition(300, 500);
    startButton.setFillColor(sf::Color::Transparent);
    startButton.setOutlineThickness(2);
    startButton.setOutlineColor(sf::Color::White);

    while (window.isOpen()) {
        handleEvents();
        draw();
    }
}

void PrecisionCustomizationWindow::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (modeSlider.getGlobalBounds().contains(mousePosition.x, mousePosition.y) || 
                modeHandle.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Handle mode slider dragging
                float relativePosition = mousePosition.x - modeSlider.getPosition().x;
                float percentage = relativePosition / modeSlider.getSize().x;
                moveModeSliderHandle(percentage);
            }

            if (radiusSlider.getGlobalBounds().contains(mousePosition.x, mousePosition.y) ||
                radiusHandle.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Handle radius slider dragging
                float relativePosition = mousePosition.x - radiusSlider.getPosition().x;
                float percentage = relativePosition / radiusSlider.getSize().x;
                moveRadiusSliderHandle(percentage);
            }

            if (speedSlider.getGlobalBounds().contains(mousePosition.x, mousePosition.y) ||
                speedHandle.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Handle speed slider dragging
                float relativePosition = mousePosition.x - speedSlider.getPosition().x;
                float percentage = relativePosition / speedSlider.getSize().x;
                moveSpeedSliderHandle(percentage);
            }
            if (lifetimeSlider.getGlobalBounds().contains(mousePosition.x, mousePosition.y) ||
                lifetimeHandle.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Handle lifetime slider dragging
                float relativePosition = mousePosition.x - speedSlider.getPosition().x;
                float percentage = relativePosition / lifetimeSlider.getSize().x;
                moveLifetimeSliderHandle(percentage);
            }
            if (startButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Start the game with selected settings
                std::cout << "Starting the game!" << std::endl;
                window.close();
                Precision precisionWnd;
                precisionWnd.runPrecisionGame(modeValue, radiusValue, speedValue, lifetimeValue);
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // Reset the slider dragging state
                isModeSliderDragging = false;
                isRadiusSliderDragging = false;
                isSpeedSliderDragging = false;
                isLifetimeSliderDragging = false;

            }
        }
        else if (event.type == sf::Event::MouseMoved) {
            if (isModeSliderDragging) {
                // Handle mode slider dragging
                float relativePosition = event.mouseMove.x - modeSlider.getPosition().x;
                float percentage = relativePosition / modeSlider.getSize().x;
                moveModeSliderHandle(percentage);
            }

            if (isRadiusSliderDragging) {
                // Handle radius slider dragging
                float relativePosition = event.mouseMove.x - radiusSlider.getPosition().x;
                float percentage = relativePosition / radiusSlider.getSize().x;
                moveRadiusSliderHandle(percentage);
            }

            if (isSpeedSliderDragging) {
                // Handle speed slider dragging
                float relativePosition = event.mouseMove.x - speedSlider.getPosition().x;
                float percentage = relativePosition / speedSlider.getSize().x;
                moveSpeedSliderHandle(percentage);
            }
            if (isLifetimeSliderDragging) {
                // Handle lifetime slider dragging
                float relativePosition = event.mouseMove.x - lifetimeSlider.getPosition().x;
                float percentage = relativePosition / lifetimeSlider.getSize().x;
                moveLifetimeSliderHandle(percentage);
            }
        }
    }
}


void PrecisionCustomizationWindow::moveModeSliderHandle(float percentage) {
    float handlePosition = modeSlider.getPosition().x + percentage * modeSlider.getSize().x;
    handlePosition = std::max(handlePosition, modeSlider.getPosition().x);
    handlePosition = std::min(handlePosition, modeSlider.getPosition().x + modeSlider.getSize().x);

    modeHandle.setPosition(handlePosition, modeSlider.getPosition().y);

    // Update the selected mode based on the handle position
    float sectionWidth = modeSlider.getSize().x / 3.0f;

    if (handlePosition < modeSlider.getPosition().x + sectionWidth) {
        // Handle in the "easy" section
        std::cout << "Selected mode: Easy" << std::endl;
        modeValue = 1;
        isModeSliderDragging = true;
        modeValText.setString("Easy");
        modeValText.setFillColor(sf::Color::Green);


    }
    else if (handlePosition < modeSlider.getPosition().x + 2 * sectionWidth) {
        // Handle in the "medium" section
        std::cout << "Selected mode: Medium" << std::endl;
        modeValue = 2;
        isModeSliderDragging = true;
        modeValText.setString("Medium");
        modeValText.setFillColor(sf::Color::Yellow);


    }
    else {
        // Handle in the "hard" section
        std::cout << "Selected mode: Hard" << std::endl;
        modeValue = 3;
        isModeSliderDragging = true;
        modeValText.setString("Hard");
        modeValText.setFillColor(sf::Color::Red);

    }
}

void PrecisionCustomizationWindow::moveRadiusSliderHandle(float percentage) {
    float handlePosition = radiusSlider.getPosition().x + percentage * radiusSlider.getSize().x;
    handlePosition = std::max(handlePosition, radiusSlider.getPosition().x);
    handlePosition = std::min(handlePosition, radiusSlider.getPosition().x + radiusSlider.getSize().x);

    radiusHandle.setPosition(handlePosition, radiusSlider.getPosition().y);
    int sliderMax = 30;
    float radVal = std::round(percentage * sliderMax); //sliderMax is how far the slider reaches 
    std::cout << static_cast<int>(radVal) << std::endl;

    radiusValue = radVal;
    if (radiusValue < 1) {
        radiusValue = 1;
    }
    if (radiusValue > sliderMax) {
        radiusValue = sliderMax;
    }
    std::cout << "Radius: " << radiusValue << std::endl;

    isRadiusSliderDragging = true;

    radiusValText.setString(std::to_string(radiusValue));

}



void PrecisionCustomizationWindow::moveSpeedSliderHandle(float percentage) {
    float handlePosition = speedSlider.getPosition().x + percentage * speedSlider.getSize().x;
    handlePosition = std::max(handlePosition, speedSlider.getPosition().x);
    handlePosition = std::min(handlePosition, speedSlider.getPosition().x + speedSlider.getSize().x);

    speedHandle.setPosition(handlePosition, speedSlider.getPosition().y);
    int sliderMax = 10;


    float spdVal = std::round(percentage * sliderMax);
    std::cout << static_cast<int>(spdVal) << std::endl;
    speedValue = spdVal;

    if (speedValue < 1) {
        speedValue = 1;
    }
    if (speedValue > sliderMax) {
        speedValue = sliderMax;
    }

    isSpeedSliderDragging = true;
    speedValText.setString(std::to_string(speedValue));

}

void PrecisionCustomizationWindow::moveLifetimeSliderHandle(float percentage) {
    float handlePosition = lifetimeSlider.getPosition().x + percentage * lifetimeSlider.getSize().x;
    handlePosition = std::max(handlePosition, lifetimeSlider.getPosition().x);
    handlePosition = std::min(handlePosition, lifetimeSlider.getPosition().x + lifetimeSlider.getSize().x);

    lifetimeHandle.setPosition(handlePosition, lifetimeSlider.getPosition().y);
    int sliderMax = 10;


    float lifeVal = std::round(percentage * sliderMax);
    std::cout << static_cast<int>(lifeVal) << std::endl;
    lifetimeValue = lifeVal;

    if (lifetimeValue < 1) {
        lifetimeValue = 1;
    }
    if (lifetimeValue > sliderMax) {
        lifetimeValue = sliderMax;
    }

    isLifetimeSliderDragging = true;
    lifetimeValText.setString(std::to_string(lifetimeValue));
}


void PrecisionCustomizationWindow::draw() {
    window.clear();
    window.draw(modeText);
    window.draw(radiusText);
    window.draw(speedText);
    window.draw(lifetimeText);

    window.draw(modeValText);
    window.draw(radiusValText);
    window.draw(speedValText);
    window.draw(lifetimeValText);

    window.draw(startText);

    window.draw(modeSlider);
    window.draw(radiusSlider);
    window.draw(speedSlider);
    window.draw(lifetimeSlider);


    window.draw(modeHandle);
    window.draw(radiusHandle);
    window.draw(speedHandle);
    window.draw(lifetimeHandle);

    window.draw(startButton);

    window.display();
}
