#include "Decal.hpp"


Decal::Decal(DecalType decaltype, sf::Vector2f pos, float rot)
    : StillObject(decaltype, pos, rot), Sound(decaltype.sound)
{
    Sound::playSound();
}
