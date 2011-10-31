#include "MovingEntity.hpp"

float MovingEntity::getSpeed()
{
    return speed;
}

//set the current speed
void MovingEntity::setSpeed(float speed)
{
    this->speed = speed;
}

std::string MovingEntity::getName()
{
    return name;
}

void MovingEntity::setName(std::string name)
{
    this->name = name;
}
