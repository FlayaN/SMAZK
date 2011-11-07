#include "Storage.hpp"
#include <iostream>

Storage::Storage()
{
    random.SetSeed(time(0));
}

Storage::Storage& Storage::getInstance()
{
    static Storage instance;
    return instance;
}

EnemyType Storage::getEnemyType(int index)
{
    return enemies[index];
}

EnemyType Storage::getEnemyType(std::string name)
{
    for(unsigned int i = 0; i < enemies.size(); ++i)
    {
        if(enemies[i].name == name)
        {
            return enemies[i];
        }
    }
    std::cout << "Error in enemies.ini" << std::endl;
    exit(0);
}

void Storage::setEnemyTypes(std::vector<EnemyType> v)
{
    enemies = v;
}

ProjectileType Storage::getProjectileType(int index)
{
    return projectiles[index];
}

ProjectileType Storage::getProjectileType(std::string name)
{
    for(unsigned int i = 0; i < projectiles.size(); ++i)
    {
        if(projectiles[i].name == name)
        {
            return projectiles[i];
        }
    }
    std::cout << "Error in projectiles.ini" << std::endl;
    exit(0);
}

void Storage::setProjectileTypes(std::vector<ProjectileType> v)
{
    projectiles = v;
}

ParticleType Storage::getParticleType(int index)
{
    return particles[index];
}

ParticleType Storage::getParticleType(std::string name)
{
    for(unsigned int i = 0; i < particles.size(); ++i)
    {
        if(particles[i].name == name)
        {
            return particles[i];
        }
    }
    std::cout << "Error in particles.ini" << std::endl;
    exit(0);
}

void Storage::setParticleTypes(std::vector<ParticleType> v)
{
    particles = v;
}

WeaponType Storage::getWeaponType(int index)
{
    return weapons[index];
}

WeaponType Storage::getWeaponType(std::string name)
{
    for(unsigned int i = 0; i < weapons.size(); ++i)
    {
        if(weapons[i].name == name)
        {
            return weapons[i];
        }
    }
    std::cout << "Error in weapons.ini" << std::endl;
    exit(0);
}

void Storage::setWeaponTypes(std::vector<WeaponType> v)
{
    weapons = v;
}

DecalType Storage::getDecalType(int index)
{
    return decals[index];
}

DecalType Storage::getDecalType(std::string name)
{
    for(unsigned int i = 0; i < decals.size(); ++i)
    {
        if(decals[i].name == name)
        {
            return decals[i];
        }
    }
    std::cout << "Error in decals.ini" << std::endl;
    exit(0);
}

void Storage::setDecalTypes(std::vector<DecalType> v)
{
    decals = v;
}

PowerUpType Storage::getPowerUpType(int index)
{
    return powerups[index];
}

PowerUpType Storage::getPowerUpType(std::string name)
{
    for(unsigned int i = 0; i < powerups.size(); ++i)
    {
        if(powerups[i].name == name)
        {
            return powerups[i];
        }
    }
    std::cout << "Error in powerups.ini" << std::endl;
    exit(0);
}

void Storage::setPowerUpTypes(std::vector<PowerUpType> v)
{
    powerups = v;
}

WaveType Storage::getWaveType(int index)
{
    return waves[index];
}

void Storage::setWaveTypes(std::vector<WaveType> v)
{
    waves = v;
}

void Storage::setImages()
{
    sf::Image tempimage;
    std::string name;
    for(unsigned int i = 0; i < enemies.size(); i++)
    {
        tempimage.LoadFromFile(enemies[i].model);
        name = enemies[i].name;
        imagemap[name] = tempimage;
    }
    for(unsigned int i = 0; i < projectiles.size(); i++)
    {
        tempimage.LoadFromFile(projectiles[i].model);
        name = projectiles[i].name;
        imagemap[name] = tempimage;
    }
    for(unsigned int i = 0; i < particles.size(); i++)
    {
        tempimage.LoadFromFile(particles[i].model);
        name = particles[i].name;
        imagemap[name] = tempimage;
    }
    for(unsigned int i = 0; i < weapons.size(); i++)
    {
        tempimage.LoadFromFile(weapons[i].model);
        name = weapons[i].name;
        imagemap[name] = tempimage;
    }

    for(unsigned int i = 0; i < decals.size(); i++)
    {
        tempimage.LoadFromFile(decals[i].model);
        name = decals[i].name;
        imagemap[name] = tempimage;
    }

    for(unsigned int i = 0; i < powerups.size(); i++)
    {
        tempimage.LoadFromFile(powerups[i].model);
        name = powerups[i].name;
        imagemap[name] = tempimage;
    }
}

sf::Image& Storage::getImage(std::string name)
{
    return (*imagemap.find(name)).second;
}

float Storage::getRandom(float begin, float end)
{
    return random.Random(begin, end);
}

int Storage::getRandom(int begin, int end)
{
    return random.Random(begin, end);
}
