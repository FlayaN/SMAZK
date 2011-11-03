#include <string>
#include "StillObject.hpp"

#ifndef WEAPONqqq
#define WEAPONqqq

class Weapon : public StillObject
{
public:
    Weapon(){}

    Weapon(float attackSpeed, std::string name, std::string projectile);

    void updateTimers(float elapsedTime);
    bool isAttackReady();
    std::string getProjectile();

private:
    float attackSpeed;
    std::string projectile;
    float attackCooldown;
};

#endif
