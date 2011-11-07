#include <string>
#include "StillObject.hpp"
#include "DecalType.hpp"

#ifndef DECALqqq
#define DECALqqq

class Decal : public StillObject
{
public:
    Decal(){}

    Decal(DecalType decaltype, sf::Vector2f pos, float rot)
    : StillObject(decaltype, pos, rot) {}

private:

};

#endif

