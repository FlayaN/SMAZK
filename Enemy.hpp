#include <string>
#include "MovingEntity.hpp"


class Enemy : public MovingEntity
{
public:

    Enemy(float speed,int health=100,std::string type="zombie")
    : MovingEntity(speed), health(health), type(type) {}

    int getHealth();
    void setHealth(int health);




private:

    int health;
    std::string type;

};
