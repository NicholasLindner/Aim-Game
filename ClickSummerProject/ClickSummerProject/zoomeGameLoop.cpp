#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "zoom.h"

int main() {
    // Define the dimensions of your window
    const int windowWidth = 800;
    const int windowHeight = 600;

    // Create an instance of ZoomWindow
    ZoomWindow zoomWindow(windowWidth, windowHeight);

    // Vector to store all active targets
    std::vector<Target> targets;

    // Create a SFML window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Target Game");

    // Main game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check for mouse click events
            if (event.type == sf::Event::MouseButtonPressed) {
                // Get the position of the mouse click
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Check if the click is within a target
                for (const Target& target : targets) {
                    sf::Vector2f targetPos(target.x, target.y);
                    float targetRadius = target.size; // radius of target

                    // Compute distance between the mouse click and the target's center
                    sf::Vector2f diff = sf::Vector2f(mousePos) - targetPos;
                    float distance = std::sqrt(diff.x * diff.x + diff.y * diff.y);

                    // If the distance is less than or equal to the target's radius, the target was clicked
                    if (distance <= targetRadius) {
                        std::cout << "A target was clicked!\n";
                        // Add code here to handle the target being clicked, such as increasing the score or removing the target
                    }
                }
            }
        }

        // Generate a new target every 60 frames (approximately once per second)
        static int counter = 0;
        if (counter++ % 60 == 0) {
            targets.push_back(zoomWindow.generateTarget());
        }

        // Iterate through targets and update their positions
        for (Target& target : targets) {
            target.x += target.dx;
            target.y += target.dy;

            // If a target goes off-screen, delete it
            if (target.x < 0 || target.x > windowWidth || target.y < 0 || target.y > windowHeight) {
                targets.erase(std::remove(targets.begin(), targets.end(), target), targets.end());
            }
        }

        // Clear the window
        window.clear();

        // Draw all targets
        // In your game loop, when rendering targets
        for (const Target& target : targets) {
            sf::CircleShape targetCircle(target.size); // Set circle radius to target's size
            targetCircle.setFillColor(sf::Color::Red);
            targetCircle.setPosition(target.x - target.size, target.y - target.size); // adjust position so that target.x and target.y is the center of the circle
            window.draw(targetCircle);
        }


        // Display what has been drawn to the window
        window.display();
    }

    return 0;
}
