#pragma once
#include <SFML/Audio.hpp>
#include <string>

class MusicPlayer
{
public:
    static MusicPlayer& getInstance();

    void playMusic(const std::string& filename);
    void stopMusic();

private:
    sf::Music music;

    MusicPlayer();
    MusicPlayer(MusicPlayer const&);
    void operator=(MusicPlayer const&);
};
