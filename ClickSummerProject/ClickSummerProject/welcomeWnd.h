#pragma once
#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include "quickshot.h"
#include "doubleshot.h"
#include "precision.h"
#include "zoom.h"
#include "precisionCustomizerWnd.h"
#include "settingsWnd.h"
#include "music.h"


class WelcomeWindow {
public:
    WelcomeWindow();    
    void handleEvents();
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;
    sf::Text button1Text;
    sf::Text button2Text;
    sf::Text button3Text;
    sf::Text button4Text;
    sf::Text crosshairButtonText;

    sf::RectangleShape button1;
    sf::RectangleShape button2;
    sf::RectangleShape button3;
    sf::RectangleShape button4;
    sf::RectangleShape settingsButton;

    sf::Texture gearsTexture;
    sf::Sprite gearsSprite;


    int selectedGameMode;
    void initWelcomeStuff();
    void draw();


};