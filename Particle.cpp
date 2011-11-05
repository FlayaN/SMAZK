#include <string>
#include "Particle.hpp"
#include <iostream>

Particle::Particle(ParticleType particletype, float speed = 1.0f)
    : MovingEntity(particletype, speed)
{
    sf::Randomizer random;
    random.SetSeed(5);
    duration = particletype.duration;// * (random.Random(particletype.duration-particletype.duration/2, particletype.duration+particletype.duration/2));

    //std::cout << particletype.duration << " : " << duration << std::endl;

}

int Particle::getDuration()
{
    return duration;
}

void Particle::updateTimers(float elapsedTime)
{
    duration -= elapsedTime;
    if (duration < 0) setDead();
}
