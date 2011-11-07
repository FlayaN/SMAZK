#include "Weapon.hpp"
#include "Projectile.hpp"

#include <iostream>

Weapon::Weapon(float attackSpeed, std::string name, std::string projectile)
    : projectile(projectile), attackSpeed(attackSpeed), StillObject(name)
{
    attackCooldown = 0;
}
Weapon::Weapon(WeaponType weapontype, sf::Vector2f pos, float rot)
    : StillObject(weapontype, pos, rot), attackSpeed(weapontype.speed), ammo(weapontype.ammo), projectile(weapontype.projectile)
{
    attackCooldown = 0;
}

void Weapon::updateTimers(float elapsedTime)
{
    attackCooldown -= elapsedTime;
    if (attackCooldown < 0) attackCooldown = 0;
}

bool Weapon::isAttackReady()
{
    return (attackCooldown <= 0);
}

std::string Weapon::getProjectile()
{
    return projectile;
}

void Weapon::attack()
{
    attackCooldown = attackSpeed;
}

int Weapon::getAmmo()
{
    return ammo;
}


