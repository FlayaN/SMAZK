#include "SFML/Audio.hpp"

#include <string>
#include <iostream>

#ifndef SOUNDqqq
#define SOUNDqqq

class Sound
{
public:
    Sound(){}
    Sound(std::string soundPath);

    void playSound();

private:
    sf::Sound sound;
    sf::SoundBuffer soundBuffer;
    std::string soundPath;
};
#endif
