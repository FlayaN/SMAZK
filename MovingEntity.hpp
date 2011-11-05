#include "EnemyType.hpp"
#include "ProjectileType.hpp"
#include "ParticleType.hpp"
#include "SFML/Graphics.hpp"
#include "Storage.hpp"
#include <string>

#ifndef MOVEINGENTITYdef
#define MOVEINGENTITYdef

class MovingEntity : public sf::Sprite
{
public:
    MovingEntity(float speed = 2.0f) : speed(speed), dead(false) {}

    MovingEntity(ProjectileType projectiletype);

    MovingEntity(EnemyType enemytype);

    MovingEntity(ParticleType particletype, float speed);

    float getSpeed();
    void setSpeed(float speed);

    std::string getName();
    void setName(std::string name);

    bool isDead();
    void setDead();

private:
    float speed;
    std::string name;
    bool dead;
};

namespace movingEntity
{
    bool isDead(MovingEntity me);
}
#endif
