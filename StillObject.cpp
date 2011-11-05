#include <string>
#include "StillObject.hpp"

StillObject::StillObject(DecalType decaltype, sf::Image& image)
: name(decaltype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(image);
    this->SetScaleX(decaltype.scale);
    this->SetScaleY(decaltype.scale);
}

StillObject::StillObject(WeaponType weapontype, sf::Image& image)
: name(weapontype.name), dead(false)
{
    //std::cout << dead << std::endl;
    this->SetImage(image);
    this->SetScaleX(weapontype.scale);
    this->SetScaleY(weapontype.scale);
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
