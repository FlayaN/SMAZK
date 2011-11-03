#include "Weapon.hpp"
#include "Projectile.hpp"

Weapon::Weapon(float attackSpeed, std::string name, std::string projectile)
    : projectile(projectile), attackSpeed(attackSpeed), StillObject(name)
{
    attackCooldown = 0;
}

void Weapon::updateTimers(float elapsedTime)
{
    updateTimers(elapsedTime);
    attackCooldown -= elapsedTime;
    if (attackCooldown < 0) attackCooldown = 0;
}

bool Weapon::isAttackReady()
{
    return (attackCooldown = 0);
}

std::string Weapon::getProjectile()
{
    return projectile;
}


