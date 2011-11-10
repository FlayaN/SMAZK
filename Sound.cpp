#include "Sound.hpp"

Sound::Sound(std::string soundPath)
{
    /*soundBuffer.LoadFromFile(soundPath);
    std::cout << soundBuffer.GetDuration() << std::endl;
    sound.SetBuffer(soundBuffer);
    std::cout << sound.GetBuffer() << std::endl;*/
    this->soundPath = soundPath;
}

void Sound::playSound()
{
    soundBuffer.LoadFromFile(soundPath);
    sound.SetBuffer(soundBuffer);
    sound.Play();
}
