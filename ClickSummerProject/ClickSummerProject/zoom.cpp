#include "zoom.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <random>
#include <ctime>
constexpr double PI = 3.14159265358979323846;


Target::Target(float x, float y, float dx, float dy, float size) {
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->size = size;
}


ZoomWindow::ZoomWindow(int width, int height) {
    this->width = width;
    this->height = height;

    // The "distX" and "distY" objects are uniform real number generators
    // We're initializing them to generate numbers between 0 and width/height
    this->distX = std::uniform_real_distribution<float>(0, width);
    this->distY = std::uniform_real_distribution<float>(0, height);
    this->distDirection = std::uniform_real_distribution<float>(0, 2 * PI);

    // Seed the random number generator with the current time
    this->rng.seed(std::time(nullptr));
}

Target ZoomWindow::generateTarget() {
    // Generate a random position along the edge of the screen
    float x, y, angle;
    int side = rng() % 4; // Pick one of the four sides of the screen
    switch (side) {
    case 0: // left side
        x = 0;
        y = distY(rng);
        break;
    case 1: // right side
        x = width;
        y = distY(rng);
        break;
    case 2: // bottom side
        x = distX(rng);
        y = 0;
        break;
    case 3: // top side
        x = distX(rng);
        y = height;
        break;
    }

    // Generate a random direction
    angle = distDirection(rng);

    // Generate a random size for the target
    std::uniform_real_distribution<> distSize(10, 50); // Randomly select size between 10 and 50
    float size = distSize(rng);

    // Create a target with the generated position, direction, and size
    return Target(x, y, std::cos(angle), std::sin(angle), size);
}

