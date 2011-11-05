#include "SFML/Graphics.hpp"
#include "DecalType.hpp"
#include "WeaponType.hpp"
#include "Storage.hpp"

#include <string>

#ifndef STILLOBJECTqqq
#define STILLOBJECTqqq

class StillObject : public sf::Sprite
{
public:
    StillObject(std::string name = "noname") : name(name) {}

    StillObject(DecalType decaltype);

    StillObject(WeaponType weapontype);

    std::string getName();
    void setName(std::string name);

    bool isDead();
    void setDead();

private:
    std::string name;
    bool dead;
};

namespace stillObject
{
    bool isDead(StillObject so);
}

#endif
