#pragma once
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


class PrecisionScoreWindow {
public:
    PrecisionScoreWindow(const int& shotsHit, const int& shotsMissed, const int& totalTime);
    void handleEvents();
   
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;

    sf::Text timeText;
    sf::Text shotsMissedText;
    sf::Text shotsHitText;
    

    sf::RectangleShape homeButton;
    sf::Text homeButtonText;


    int selectedGameMode;

    int shotsMissed;
    int shotsHit;
    int totalTime;


    void initPrecisionScoreStuff();
    void draw();


};