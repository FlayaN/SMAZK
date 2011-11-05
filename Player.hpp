#include "MovingEntity.hpp"
#include "Weapon.hpp"

#ifndef PLAYERqqq
#define PLAYERqqq

class Player : public MovingEntity
{
public:
    Player(){}

    Player(float speed, int hp, Weapon weapon): weapon(weapon), MovingEntity(speed), hp(hp) {}

    int getHp();

    void setHp(int hp);

    void updateTimers(float elapsedTime);
    Weapon& getWeapon();

    void attack();

private:

    Weapon weapon;
    int hp;
};

#endif
