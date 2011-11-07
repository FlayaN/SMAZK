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

float Player::getDmg()
{
    return Storage::getInstance().getProjectileType(weapon.getProjectile()).damage * powerUp.getDamageScale();
}

float Player::getSpeed()
{
    return MovingEntity::getSpeed()*powerUp.getSpeedScale();
}

void Player::updateTimers(float elapsedTime)
{
    weapon.updateTimers(elapsedTime);
    powerUpDuration -= elapsedTime;
    if(powerUpDuration <= 0)
    {
        powerUp.setDamageScale(1);
        powerUp.setSpeedScale(1);
    }
}

void Player::attack()
{
    weapon.attack();
}

void Player::setPowerUp(PowerUp powerUp)
{
    this->powerUp = powerUp;
    powerUpDuration = 20;
}
