#include "Decal.hpp"


Decal::Decal(DecalType decaltype, sf::Vector2f pos, float rot, sf::Vector2f scale)
    : StillObject(decaltype, pos, rot), Sound(decaltype.sound)
{
    this->SetScale(scale*decaltype.scale);
}
