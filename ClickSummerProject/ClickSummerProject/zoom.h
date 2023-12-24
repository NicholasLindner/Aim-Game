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
#include <random>
#ifndef ZOOM_H
#define ZOOM_H


class Target {
public:
    float x, y, dx, dy;
    float size;
    Target(float x, float y, float dx, float dy, float size);
};

class ZoomWindow {
public:
    ZoomWindow(int width, int height);
    Target generateTarget();

private:
    int width, height;
    std::mt19937 rng;
    std::uniform_real_distribution<float> distX, distY, distDirection;
};

#endif

