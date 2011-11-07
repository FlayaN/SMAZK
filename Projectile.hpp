#include "MovingEntity.hpp"

#ifndef PROJECTILEqqq
#define PROJECTILEqqq

class Projectile : public MovingEntity
{
public:
    Projectile(ProjectileType projectiletype, sf::Vector2f pos, float rot)
    : MovingEntity(projectiletype, pos, rot), dmg(projectiletype.damage) {}

    int getDmg();

private:

    int dmg;
};

#endif
