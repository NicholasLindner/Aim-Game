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
#include "precisionScoreWnd.h"
#include <vector>

#ifndef PRECISION_H
#define PRECISION_H

extern std::string gameCrosshair;

class Precision {
    public:
        int x;
        int y;
        std::chrono::steady_clock::time_point creationTime;

        Precision();
        bool isExpired() const;
        void runPrecisionGame(int mode, int circleRadius, int newCircleInitSpeed, int circleLifetime);
        int getOngoingMillis();
        int CIRCLE_LIFETIME = 1;


    private:
        int missedShots = 0;
        int hitShots = 0;
        sf::Text missedShotsText;
        sf::Text livesText;
        sf::Texture heartTexture;
        sf::Sprite heartSprite;


        sf::SoundBuffer targetMiss;
        sf::SoundBuffer targetHit;
        sf::SoundBuffer targetGone;

        sf::Sound soundHit;
        sf::Sound soundMiss;
        sf::Sound soundGone;


        int CIRCLE_RADIUS = 1;
        int CIRCLE_INIT_SPEED = 1;


};

#endif // PRECISION_H
