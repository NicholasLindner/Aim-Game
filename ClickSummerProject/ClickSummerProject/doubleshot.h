#pragma once
#include <SFML/Graphics.hpp>
#include "sfml/graphics.hpp"
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <map>
#include <dos.h>
#include <thread>
#include <SFML/Audio.hpp>
#include "doubleshotScoreWnd.h"

//#include "doubleshotScoreWnd.h"
//#include "doubleshotScoreWnd.cpp"
extern std::string gameCrosshair;



class DoubleshotWindow {
public:
    DoubleshotWindow();
    void handleEvents();
    void draw();



private:
    sf::Font font;
    sf::Text hitsText;
    sf::Text secondTargetTime;
    sf::Text thirdTargetTime;
    sf::Text fourthTargetTime;
    sf::Text fifthTargetTime;
    sf::Text missedShotsText;
    sf::Text livesText;

    sf::RenderWindow window;
    sf::Text title;
    sf::Text targetText;
    sf::CircleShape target_one;
    sf::CircleShape target_two;

    sf::SoundBuffer targetMiss;
    sf::SoundBuffer targetHit;
    sf::SoundBuffer targetGone;

    sf::Sound soundHit;
    sf::Sound soundMiss;
    sf::Sound soundGone;

    sf::Texture heartTexture;
    std::vector<sf::RectangleShape> hearts;


    void initDoubleshotTargets();
    void initDoubleshotScreen();
    void initText();
    void tempHideTarget1();
    void tempHideTarget2();

    void startTimer();
    void stopTimer();
    void resetTimer();
    int getOngoingMillis();
    int getTotalMillis();
    void getTargetTime();
    bool hasEnded() { return false; }

    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point reactionTime;

    int totalLives = 5;
    int totalTargets = 0;
    int hitTargets = 0;
    int missedTargets = 0;
    int selectedGameMode;
    int waitTime;
    int stoppedSecs = 0;
    int numTargetResets = 0;
    int numTargetAppearances = 0;
    int doubleClickNumber = 0;
    int missedShots = 0;
    int setTargetOneHit = 0;
    int setTargetTwoHit = 0;

    bool paused = false;
    bool allowActivateTargets = true;
    bool allowActivateGoneSound = true;

    int livesLeft = 5;

    int time1;
    int time2;
    int time3;
    int time4;
    int time5;

    int averageTime;

};