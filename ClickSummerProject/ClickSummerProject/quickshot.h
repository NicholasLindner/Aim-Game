#pragma once
#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <map>
#include <dos.h>
#include <thread>
#include "quickshotScorewnd.h"
#include <SFML/Audio.hpp>


extern std::string gameCrosshair;

class QuickshotWindow {
public:
    QuickshotWindow();
    void handleEvents();
    void draw();
 


private:
    sf::Font font;
    sf::Text firstTargetTime;
    sf::Text secondTargetTime;
    sf::Text thirdTargetTime;
    sf::Text fourthTargetTime;
    sf::Text fifthTargetTime;
    sf::Text missedShotsText;

    sf::Sprite cursorSprite;

    sf::SoundBuffer targetMiss;
    sf::SoundBuffer targetHit;
    sf::SoundBuffer targetGone;

    sf::Sound soundHit;
    sf::Sound soundMiss;
    sf::Sound soundGone;

    sf::RenderWindow window;
    sf::Text title;
    sf::Text targetText;
    sf::CircleShape target;
   
    int selectedGameMode;
    void initQuickshotTarget();
    void initQuickshotScreen();
    void initText();
    void tempHideTarget();

    void startTimer();
    void stopTimer();
    void resetTimer();
    int getOngoingMillis();
    int getTotalMillis();
    void getTargetTime();
    bool hasEnded() { return false; }

    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point reactionTime;

    int waitTime;
    int stoppedSecs = 0;
    bool paused = false;
    int numTargetResets = 0;
    int numTargetAppearances = 0;
    int clickNumber = 0;
    int missedShots = 0;

    int time1;
    int time2;
    int time3;
    int time4;
    int time5;

    int averageTime;

};