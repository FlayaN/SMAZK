#include <string>
#include "StillObject.hpp"
#include "PowerUpType.hpp"

#ifndef POWERUPqqq
#define POWERUPqqq

class PowerUp : public StillObject
{
public:
    PowerUp(): speedScale(1), damageScale(1){}

    PowerUp(PowerUpType poweruptype, sf::Vector2f pos, float rot)
        : StillObject(poweruptype, pos, rot), speedScale(poweruptype.speedScale), damageScale(poweruptype.damageScale), heal(poweruptype.heal) {}

    int getHeal();

    float getSpeedScale();
    void setSpeedScale(float speedScale);

    float getDamageScale();
    void setDamageScale(float damageScale);


private:
    int heal;
    float speedScale, damageScale;
};

#endif

