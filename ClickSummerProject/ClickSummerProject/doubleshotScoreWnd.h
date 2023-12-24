#pragma once
#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include "doubleshot.h"
#include "welcomewnd.h"
#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <map>
#include <dos.h>
#include <thread>


class DoubleshotScoreWindow {
public:
    DoubleshotScoreWindow(int shotsHit);
    void handleEvents();
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;

    sf::Text shotsHitText;


    sf::RectangleShape homeButton;
    sf::Text homeButtonText;


    int selectedGameMode;

    int shotsHit;


    int avgTime;

    void initDoubleshotScoreStuff();
    void draw();


};