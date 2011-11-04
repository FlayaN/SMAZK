#include "MovingEntity.hpp"

#include <iostream>

MovingEntity::MovingEntity(EnemyType enemytype, sf::Image& image)
: speed(enemytype.speed), name(enemytype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(image);
    this->SetScaleX(enemytype.scale);
    this->SetScaleY(enemytype.scale);
}

MovingEntity::MovingEntity(ProjectileType projectiletype, sf::Image& image)
: speed(projectiletype.speed), name(projectiletype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(image);
    this->SetScaleX(projectiletype.scale);
    this->SetScaleY(projectiletype.scale);
}

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

bool MovingEntity::isDead()
{
    return dead;
}

bool movingEntity::isDead(MovingEntity me)
{

    return me.isDead();
}

void MovingEntity::setDead()
{
    dead = true;
}
