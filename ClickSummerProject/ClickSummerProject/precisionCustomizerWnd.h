#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include "quickshot.h"
#include "welcomewnd.h"
#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <map>
#include <dos.h>
#include <thread>

#ifndef PRECISIONCUSTOMIZATIONWINDOW_H
#define PRECISIONCUSTOMIZATIONWINDOW_H

#include <SFML/Graphics.hpp>

class PrecisionCustomizationWindow {
public:
    void runCustomizationWindow();

    int getModeValue() const {
        return modeValue;
    }

    int getRadiusValue() const {
        return radiusValue;
    }

    int getSpeedValue() const {
        return speedValue;
    }
    int lifetimeValueOG = 1;

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text modeText;
    sf::Text radiusText;
    sf::Text speedText;
    sf::Text lifetimeText;
    sf::Text startText;
    sf::Text modeValText;
    sf::Text radiusValText;
    sf::Text speedValText;
    sf::Text lifetimeValText;


    sf::RectangleShape startButton;
    sf::RectangleShape modeSlider;
    sf::RectangleShape radiusSlider;
    sf::RectangleShape speedSlider;
    sf::RectangleShape lifetimeSlider;
    sf::RectangleShape modeHandle;
    sf::RectangleShape radiusHandle;
    sf::RectangleShape speedHandle;
    sf::RectangleShape lifetimeHandle;



    int modeValue = 1;
    int radiusValue = 1;
    int speedValue = 1;
    int lifetimeValue = 1;

    bool isModeSliderDragging = false;
    bool isRadiusSliderDragging = false;
    bool isSpeedSliderDragging = false;
    bool isLifetimeSliderDragging = false;


    //void initializeSliders();
    void handleEvents();
    void moveModeSliderHandle(float percentage);
    void moveRadiusSliderHandle(float percentage);
    void moveSpeedSliderHandle(float percentage);
    void moveLifetimeSliderHandle(float percentage);

    //void handleStartButton(const sf::Vector2i& mousePosition);
    void draw();

    void handleModeSlider() {
        // Calculate the mode value based on the slider position
        float sliderPosition = modeSlider.getPosition().x;
        float sliderLength = modeSlider.getSize().x;
        float handlePosition = modeHandle.getPosition().x;
        float handleLength = modeHandle.getSize().x;
        float normalizedPosition = (handlePosition - sliderPosition) / (sliderLength - handleLength);

        // Update the mode value
        if (normalizedPosition < 0.33f) {
            modeValue = 1; // Easy mode
        }
        else if (normalizedPosition < 0.66f) {
            modeValue = 2; // Medium mode
        }
        else {
            modeValue = 3; // Hard mode
        }
    }
};

#endif // PRECISIONCUSTOMIZATIONWINDOW_H

