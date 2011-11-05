#include "Storage.hpp"
#include <iostream>

EnemyType Storage::getEnemyType(int index)
{
    return enemys[index];
}

void Storage::setEnemyTypes(std::vector<EnemyType> v)
{
    enemys = v;
}

ProjectileType Storage::getProjectileType(int index)
{
    return projectiles[index];
}

void Storage::setProjectileTypes(std::vector<ProjectileType> v)
{
    projectiles = v;
}

ParticleType Storage::getParticleType(int index)
{
    return particles[index];
}

void Storage::setParticleTypes(std::vector<ParticleType> v)
{
    particles = v;
}

WeaponType Storage::getWeaponType(int index)
{
    return weapons[index];
}

void Storage::setWeaponTypes(std::vector<WeaponType> v)
{
    weapons = v;
}

DecalType Storage::getDecalType(int index)
{
    return decals[index];
}
void Storage::setDecalTypes(std::vector<DecalType> v)
{
    decals = v;
}

void Storage::setImages()
{
    sf::Image tempimage;
    std::string name;
    for(int i = 0; i < enemys.size(); i++)
    {
        tempimage.LoadFromFile(enemys[i].model);
        name = enemys[i].name;
        imagemap[name] = tempimage;
    }
    for(int i = 0; i < projectiles.size(); i++)
    {
        tempimage.LoadFromFile(projectiles[i].model);
        name = projectiles[i].name;
        imagemap[name] = tempimage;
    }
    for(int i = 0; i < particles.size(); i++)
    {
        tempimage.LoadFromFile(particles[i].model);
        name = particles[i].name;
        imagemap[name] = tempimage;
    }
    for(int i = 0; i < weapons.size(); i++)
    {
        tempimage.LoadFromFile(weapons[i].model);
        name = weapons[i].name;
        imagemap[name] = tempimage;
    }

    for(int i = 0; i < decals.size(); i++)
    {
        tempimage.LoadFromFile(decals[i].model);
        name = decals[i].name;
        imagemap[name] = tempimage;
    }
}

sf::Image& Storage::getImage(std::string name)
{
    return (*imagemap.find(name)).second;
}
