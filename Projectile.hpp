#include "MovingEntity.hpp"

#ifndef PROJECTILEqqq
#define PROJECTILEqqq

class Projectile : public MovingEntity
{
public:
    Projectile(ProjectileType projectiletype)
    : MovingEntity(projectiletype), dmg(projectiletype.damage) {}

    int getDmg();

private:

    int dmg;
};

#endif
