#include "MovingEntity.hpp"
#include "Storage.hpp"

#include <iostream>

MovingEntity::MovingEntity(EnemyType enemytype, sf::Vector2f pos)
: speed(enemytype.speed), name(enemytype.name), dead(false)
{
    this->SetImage(Storage::getInstance().getImage(enemytype.name));
    this->SetScaleX(enemytype.scale);
    this->SetScaleY(enemytype.scale);
    this->SetCenter(Storage::getInstance().getImage(enemytype.name).GetWidth()/2, Storage::getInstance().getImage(enemytype.name).GetHeight()/2);
    this->SetPosition(pos);
}

MovingEntity::MovingEntity(ProjectileType projectiletype, sf::Vector2f pos, float rot)
: speed(projectiletype.speed), name(projectiletype.name), dead(false)
{
    this->SetImage(Storage::getInstance().getImage(projectiletype.name));
    this->SetScaleX(projectiletype.scale);
    this->SetScaleY(projectiletype.scale);
    this->SetCenter(Storage::getInstance().getImage(projectiletype.name).GetWidth()/2, Storage::getInstance().getImage(projectiletype.name).GetHeight()/2);
    this->SetPosition(pos);
    this->SetRotation(rot);
}

MovingEntity::MovingEntity(ParticleType particletype, sf::Vector2f pos, float rot, float speed = 1.0f)
: speed(speed), name(particletype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(Storage::getInstance().getImage(particletype.name));
    this->SetScaleX(particletype.scale);
    this->SetScaleY(particletype.scale);
    this->SetCenter(Storage::getInstance().getImage(particletype.name).GetWidth()/2, Storage::getInstance().getImage(particletype.name).GetHeight()/2);
    this->SetPosition(pos);
    this->SetRotation(rot);
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

void MovingEntity::setDead()
{
    dead = true;
}

bool movingEntity::isDead(MovingEntity me)
{

    return me.isDead();
}
