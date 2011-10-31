#include <string>
#include "MovingEntity.hpp"


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
