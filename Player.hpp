#include "MovingEntity.hpp"
#include "powerUp.hpp"
#include "Weapon.hpp"

#ifndef PLAYERqqq
#define PLAYERqqq

class Player : public MovingEntity
{
public:
    Player(){}

    Player(float speed, int hp, Weapon weapon)
    : weapon(weapon), MovingEntity(speed), hp(hp), powerUpDuration(0) {}

    int getHp();

    void setHp(int hp);

    void updateTimers(float elapsedTime);
    Weapon& getWeapon();

    float getDmg();
    float getSpeed();

    void attack();

    void setPowerUp(PowerUp powerUp);

private:


    Weapon weapon;
    int hp;
    PowerUp powerUp;
    float powerUpDuration;
};

#endif
