#include <string>
#include "Particle.hpp"
#include <iostream>

Particle::Particle(ParticleType particletype, sf::Vector2f pos, float rot, float speed = 1.0f)
    : MovingEntity(particletype, pos, rot, speed)
{
    duration = particletype.duration * (Storage::getInstance().getRandom(0.5f,1.5f));
}

int Particle::getDuration()
{
    return duration;
}

void Particle::updateTimers(float elapsedTime)
{
    duration -= elapsedTime;
    if (duration < 0)
    {
        setDead();
    }
}
