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

    MovingEntity(EnemyType enemytype, sf::Vector2f);

    MovingEntity(ProjectileType projectiletype, sf::Vector2f pos, float rot);

    MovingEntity(ParticleType particletype, sf::Vector2f pos, float rot, float speed);

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
