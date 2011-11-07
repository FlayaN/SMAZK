#include <string>
#include "StillObject.hpp"
#include "PowerUpType.hpp"

#ifndef POWERUPqqq
#define POWERUPqqq

class PowerUp : public StillObject
{
public:
    PowerUp(){}

    PowerUp(PowerUpType poweruptype, sf::Vector2f pos, float rot)
        : StillObject(poweruptype, pos, rot), speedscale(poweruptype.speedScale), damagescale(poweruptype.damageScale), heal(poweruptype.heal) {}

    int getHeal();
    float getSpeedScale();
    float getDamageScale();


private:
    int heal;
    float speedscale, damagescale;
};

#endif

