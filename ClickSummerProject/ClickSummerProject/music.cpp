#include "music.h"

MusicPlayer& MusicPlayer::getInstance()
{
    static MusicPlayer instance;
    return instance;
}

void MusicPlayer::playMusic(const std::string& filename)
{
    if (!music.openFromFile(filename))
    {
        // handle error
    }

    music.setLoop(true);
    music.play();
}

void MusicPlayer::stopMusic()
{
    music.stop();
}

MusicPlayer::MusicPlayer()
{
    // Constructor left intentionally blank
}

MusicPlayer::MusicPlayer(MusicPlayer const&)
{
    // Copy constructor left intentionally blank
}

void MusicPlayer::operator=(MusicPlayer const&)
{
    // Assignment operator left intentionally blank
}
