#include <string>
#include "MovingEntity.hpp"

#ifndef ENEMYqqq
#define ENEMYqqq

class Enemy : public MovingEntity
{
public:

    Enemy(float speed, int health=100, std::string name="zombie")
    : MovingEntity(speed, name), health(health) {}

    int getHealth();
    void setHealth(int health);

private:
    int health;
};

#endif
