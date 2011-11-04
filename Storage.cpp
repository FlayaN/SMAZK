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
}

sf::Image& Storage::getImage(std::string name)
{
    return (*imagemap.find(name)).second;
}
