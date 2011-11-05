#include "MovingEntity.hpp"
#include "ParticleType.hpp"
#include "SFML/Graphics.hpp"
#ifndef PARTICLEqqq
#define PARTICLEqqq

class Particle : public MovingEntity
{
public:
    Particle(ParticleType particletype, float speed);

    int getDuration();

    void updateTimers(float elapsedTime);

private:
    float duration;
};

#endif
