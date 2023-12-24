#pragma once
#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include "quickshot.h"
#include "doubleshot.h"
#include "precision.h"
#include "precisionCustomizerWnd.h"
#include "welcomewnd.h"
#include "music.h"


extern bool musicOn;
extern std::string gameCrosshair;

class SettingsWindow {
public:
    SettingsWindow();
    void handleEvents();
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;
    sf::Text crosshairText;
    sf::Text crosshairButtonText;
    sf::Text musicButtonText;
    sf::Text musicOnText;
    sf::Text musicOffText;

    sf::Text homeButtonText;

    sf::RectangleShape homeButton;

    sf::RectangleShape crosshairBox1;
    sf::RectangleShape crosshairBox2;
    sf::RectangleShape crosshairBox3;
    sf::RectangleShape musicButton;
    sf::RectangleShape musicButtonOff;
    sf::RectangleShape musicButtonOn;

    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;

    sf::RectangleShape button2;
    sf::RectangleShape button3;
    sf::RectangleShape button4;
    sf::RectangleShape settingsButton;

    sf::Texture gearsTexture;
    sf::Sprite gearsSprite;

    int selectedGameMode;

    void initSettingsStuff();
    void draw();

};