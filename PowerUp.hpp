#include <string>
#include "StillObject.hpp"
#include "PowerUpType.hpp"
#include "Sound.hpp"

#ifndef POWERUPqqq
#define POWERUPqqq

class PowerUp : public StillObject, public Sound
{
public:
    PowerUp(): speedScale(1), damageScale(1){}

    PowerUp(PowerUpType poweruptype, sf::Vector2f pos, float rot)
        : StillObject(poweruptype, pos, rot), Sound(poweruptype.sound), speedScale(poweruptype.speedScale), damageScale(poweruptype.damageScale), heal(poweruptype.heal), instant(poweruptype.instant){}

    int getHeal();

    float getSpeedScale();
    void setSpeedScale(float speedScale);

    float getDamageScale();
    void setDamageScale(float damageScale);

    bool isInstant();

private:
    int heal;
    float speedScale, damageScale;
    bool instant;
};

#endif

