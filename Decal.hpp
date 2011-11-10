#include <string>
#include "StillObject.hpp"
#include "DecalType.hpp"
#include "Sound.hpp"

#ifndef DECALqqq
#define DECALqqq

class Decal : public StillObject, public Sound
{
public:
    Decal(){}

    Decal(DecalType decaltype, sf::Vector2f pos, float rot);
};
#endif

