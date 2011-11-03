#include "Player.hpp"

int Player::getHp()
{
    return hp;
}
void Player::setHp(int hp)
{
    this->hp = hp;
}

Weapon& Player::getWeapon()
{
    return weapon;
}

void Player::updateTimers(float elapsedTime)
{
    weapon.updateTimers(elapsedTime);
}


