#include "MovingEntity.hpp"
#include "ParticleType.hpp"
#include "SFML/Graphics.hpp"
#ifndef PARTICLEqqq
#define PARTICLEqqq

class Particle : public MovingEntity
{
public:
    Particle(ParticleType particletype, sf::Vector2f pos, float rot, float speed);

    int getDuration();

    void updateTimers(float elapsedTime);

private:
    float duration;
};

#endif
