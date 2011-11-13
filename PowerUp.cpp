#include "PowerUp.hpp"

int PowerUp::getHeal()
{
    return heal;
}

float PowerUp::getSpeedScale()
{
    return speedScale;
}

void PowerUp::setSpeedScale(float speedScale)
{
    this->speedScale = speedScale;
}

float PowerUp::getDamageScale()
{
    return damageScale;
}

void PowerUp::setDamageScale(float damageScale)
{
    this->damageScale = damageScale;
}
