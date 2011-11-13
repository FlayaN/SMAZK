#include "Player.hpp"

int Player::getHp()
{
    return hp;
}
void Player::setHp(int hp)
{
    this->hp = hp;
    if(this->hp > 100) this->hp = 100;
}

Weapon& Player::getWeapon()
{
    return weapon;
}

void Player::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
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
    if(weapon.getAmmo() == 0) weapon = Weapon(Storage::getInstance().getWeaponType(0), sf::Vector2f(MovingEntity::GetPosition()), MovingEntity::GetRotation());
    weapon.attack();
}

void Player::setPowerUp(PowerUp powerUp)
{
    this->powerUp = powerUp;
    this->powerUp.playSound();
    powerUpDuration = 20;
}
