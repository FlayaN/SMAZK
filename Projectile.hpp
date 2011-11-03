#include "MovingEntity.hpp"

#ifndef PROJECTILEqqq
#define PROJECTILEqqq

class Projectile : public MovingEntity
{
public:
    //Projectile(){}

    Projectile(float speed, int dmg): MovingEntity(speed), dmg(dmg) {}

    int getDmg();

private:

    int dmg;
};

#endif
