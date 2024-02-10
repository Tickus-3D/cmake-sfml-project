#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("D A N C I N.ogg"))
    {
        std::cout << "Error loading sound file" << std::endl;
        return -1;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);

    sound.play();

    while (sound.getStatus() == sf::Sound::Playing)
    {
        sf::sleep(sf::seconds(0.1f));
    }

    return 0;
}