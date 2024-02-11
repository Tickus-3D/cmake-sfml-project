#include <SFML/Audio.hpp>
#include <iostream>

#include "TestClass.h"

int MusicPlayer::PlayTestMusic()
{
    sf::Music Music1; // defualt = 44100-hz

    if (!Music1.openFromFile("C:\/Users/Kyle/Documents/GitHub/cmake-sfml-project/Content/HDMI.ogg"))
    {
        std::cout << "file failed to load\n";
        return -1;
    }
    sf::Time duration = Music1.getDuration();
    float seconds = duration.asSeconds();

    std::cout << "Duration: " << seconds << " seconds" << std::endl;

    Music1.play();

    return 0;
}
