#include <string>
#include "StillObject.hpp"

StillObject::StillObject(DecalType decaltype, sf::Vector2f pos, float rot)
: name(decaltype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(Storage::getInstance().getImage(decaltype.name));
    this->SetScaleX(decaltype.scale);
    this->SetScaleY(decaltype.scale);
    this->SetCenter(Storage::getInstance().getImage(decaltype.name).GetWidth()/2, Storage::getInstance().getImage(decaltype.name).GetHeight()/2);
    this->SetPosition(pos);
    this->SetRotation(rot);
}

StillObject::StillObject(WeaponType weapontype, sf::Vector2f pos, float rot)
: name(weapontype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(Storage::getInstance().getImage(weapontype.name));
    this->SetScaleX(weapontype.scale);
    this->SetScaleY(weapontype.scale);
    this->SetCenter(Storage::getInstance().getImage(weapontype.name).GetWidth()/2, Storage::getInstance().getImage(weapontype.name).GetHeight()/2);
    this->SetPosition(pos);
    this->SetRotation(rot);
}

StillObject::StillObject(PowerUpType poweruptype, sf::Vector2f pos, float rot)
: name(poweruptype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(Storage::getInstance().getImage(poweruptype.name));
    this->SetScaleX(poweruptype.scale);
    this->SetScaleY(poweruptype.scale);
    this->SetCenter(Storage::getInstance().getImage(poweruptype.name).GetWidth()/2, Storage::getInstance().getImage(poweruptype.name).GetHeight()/2);
    this->SetPosition(pos);
    this->SetRotation(rot);
}

std::string StillObject::getName()
{
    return name;
}

void StillObject::setName(std::string name)
{
    this->name = name;
}

bool StillObject::isDead()
{
    return dead;
}

void StillObject::setDead()
{
    dead = true;
}

bool stillObject::isDead(StillObject so)
{

    return so.isDead();
}
