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


class QuickshotScoreWindow {
public:
    QuickshotScoreWindow(const int& time1, const int& time2, const int& time3, const int& time4, const int& time5);
    void handleEvents();
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title;

    sf::Text time1Text;
    sf::Text time2Text;
    sf::Text time3Text;
    sf::Text time4Text;
    sf::Text time5Text;
    sf::Text avgTimeText;


    sf::RectangleShape homeButton;
    sf::Text homeButtonText;


    int selectedGameMode;

    int time1;
    int time2;
    int time3;
    int time4;
    int time5;

    int avgTime;

    void initQuickshotScoreStuff();
    void draw();


};