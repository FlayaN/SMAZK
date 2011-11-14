#include <string>
#include "Enemy.hpp"


int Enemy::getHp()
{
    return hp;
}
void Enemy::setHp(int hp)
{
    this->hp = hp;
}

std::string Enemy::getDecal()
{
    return decal;
}

int Enemy::getDmg()
{
    return dmg;
}

