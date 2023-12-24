#include <iostream>
#include <SFML/Graphics.hpp>
#include "welcomewnd.h"
#include <istream>
#include <fstream>
#include <string>
#include <SFML/Audio.hpp>

bool musicOn = false;

std::string gameCrosshair;

std::string yellowCircleCrosshair = "newestcrosshair.png";
std::string greenCSGOCrosshair = "csgocrosshairgreen.png";
std::string blueTriangleCrosshair = "bluetrianglecrosshair.png";




int main(int argc, char* argv[]){
	WelcomeWindow welcomeWnd;
	welcomeWnd.handleEvents();
}
