#include "Sound.hpp"

Sound::Sound(std::string soundPath)
{
    this->soundPath = soundPath;
}

void Sound::playSound()
{
    if(Storage::getInstance().isSoundOn())
    {
        soundBuffer.LoadFromFile(soundPath);
        sound.SetBuffer(soundBuffer);
        sound.Play();
    }
}
