#include <string>
#include "StillObject.hpp"
#include "WeaponType.hpp"

#ifndef WEAPONqqq
#define WEAPONqqq

class Weapon : public StillObject
{
public:
    Weapon(){}

    Weapon(float attackSpeed, std::string name, std::string projectile);

    Weapon(WeaponType weapontype);

    void updateTimers(float elapsedTime);
    bool isAttackReady();
    std::string getProjectile();

    void attack();

    int getAmmo();

private:
    float attackSpeed, attackCooldown;
    std::string projectile;
    int ammo;
};

#endif
