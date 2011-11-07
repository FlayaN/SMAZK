#include "SFML/Graphics.hpp"
#include "DecalType.hpp"
#include "WeaponType.hpp"
#include "PowerUpType.hpp"

#include "Storage.hpp"

#include <string>

#ifndef STILLOBJECTqqq
#define STILLOBJECTqqq

class StillObject : public sf::Sprite
{
public:
    StillObject(std::string name = "noname") : name(name) {}

    StillObject(DecalType decaltype, sf::Vector2f pos, float rot);

    StillObject(WeaponType weapontype, sf::Vector2f pos, float rot);

    StillObject(PowerUpType poweruptype, sf::Vector2f pos, float rot);

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
