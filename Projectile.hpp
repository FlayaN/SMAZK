#include "MovingEntity.hpp"

#ifndef PROJECTILEqqq
#define PROJECTILEqqq

class Projectile : public MovingEntity
{
public:
    Projectile(ProjectileType projectiletype, sf::Image& image)
    : MovingEntity(projectiletype, image), dmg(projectiletype.damage) {}

    int getDmg();

private:

    int dmg;
};

#endif
