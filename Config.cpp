#include "Config.hpp"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <sstream>

std::vector<EnemyType> Config::getEnemys()
{
    std::vector<EnemyType> v;
    EnemyType enemy;
    std::stringstream ss;
    char* path = "resources\\ini\\enemys.ini";
    std::cout << "Enemys: " << getInt("number", 1, "init", path) << std::endl;
    char section[32];
    try{
        for(int count = 1; count <= getInt("number", 1, "init", path); count++)
        {
            ss << "Enemy";
            ss << count;
            ss >> section;

            enemy.name = getString("name", "", section, path);
            enemy.maxHp = getInt("maxhp",1, section, path);
            enemy.model = ("resources\\images\\" + getString("model","", section, path));
            enemy.speed = getFloat("speed",1.0F, section, path);
            enemy.scale = getFloat("scale",1.0F, section, path);
            enemy.particle = getString("particle","", section, path);
            enemy.decal = getString("decal","", section, path);
            enemy.weapon = getString("weapon","", section, path);
            enemy.sound = getString("sound","", section, path);
            enemy.dmg = getInt("damage", 1, section, path);

            v.push_back(enemy);
            ss.str("");
            ss.clear();
        }
    }
    catch(...)
    {
        std::cout << "error";
    }
    return v;
}
std::vector<ProjectileType> Config::getProjectiles()
{
    std::vector<ProjectileType> v;
    ProjectileType projectile;
    std::stringstream ss;
    char* path = "resources\\ini\\projectiles.ini";
    std::cout << "Projectiles: " << getInt("number", 1, "init", path) << std::endl;
    char section[32];
    try{
        for(int count = 1; count <= getInt("number", 1, "init", path); count++)
        {
            ss << "Projectile";
            ss << count;
            ss >> section;

            projectile.damage = getInt("damage", 1, section, path);
            projectile.model = ("resources\\images\\" + getString("model", "", section, path));
            projectile.name = getString("name", "", section, path);
            projectile.scale = getFloat("scale", 1.0F, section, path);
            projectile.speed = getFloat("speed", 1.0F, section, path);
            projectile.particle = getString("particle", "", section, path);
            //projectile.weapon = getString("weapon", "", section, path);

            v.push_back(projectile);
            ss.str("");
            ss.clear();
        }
    }
    catch(...)
    {
        std::cout << "error";
    }
    return v;
}
std::vector<WeaponType> Config::getWeapons()
{
    std::vector<WeaponType> v;
    WeaponType weapon;
    std::stringstream ss;
    char* path = "resources\\ini\\weapons.ini";
    std::cout << "Weapons: " << getInt("number", 1, "init", path) << std::endl;
    char section[32];
    try{
        for(int count = 1; count <= getInt("number", 1, "init", path); count++)
        {
            ss << "Weapon";
            ss << count;
            ss >> section;
            weapon.ammo = getInt("ammo", 1, section, path);
            weapon.model = ("resources\\images\\" + getString("model", "", section, path));
            weapon.name = getString("name", "", section, path);
            weapon.projectile = getString("projectile", "", section, path);
            weapon.scale = getFloat("scale", 1.0F, section, path);
            weapon.speed = getFloat("speed", 1.0F, section, path);
            v.push_back(weapon);
            ss.str("");
            ss.clear();
        }
    }
    catch(...)
    {
        std::cout << "error";
    }
    return v;
}
std::vector<PowerUpType> Config::getPowerUps()
{
    std::vector<PowerUpType> v;
    PowerUpType powerup;
    std::stringstream ss;
    char* path = "resources\\ini\\powerups.ini";
    std::cout << "PowerUps: " << getInt("number", 1, "init", path) << std::endl;
    char section[32];
    try{
        for(int count = 1; count <= getInt("number", 1, "init", path); count++)
        {
            ss << "PowerUp";
            ss << count;
            ss >> section;

            powerup.damageScale = getFloat("damagescale", 1.0F, section, path);
            powerup.speedScale = getFloat("speedscale", 1.0F, section, path);
            powerup.heal = getInt("heal", 1, section, path);
            powerup.scale = getFloat("scale", 1.0F, section, path);
            powerup.name = getString("name", "", section, path);
            powerup.model = ("resources\\images\\" + getString("model", "", section, path));

            v.push_back(powerup);
            ss.str("");
            ss.clear();
        }
    }
    catch(...)
    {
        std::cout << "error";
    }
    return v;
}
std::vector<DecalType> Config::getDecals()
{
    std::vector<DecalType> v;
    DecalType decal;
    std::stringstream ss;
    char* path = "resources\\ini\\decals.ini";
    std::cout << "Decals: " << getInt("number", 1, "init", path) << std::endl;
    char section[32];
    try{
        for(int count = 1; count <= getInt("number", 1, "init", path); count++)
        {
            ss << "Decal";
            ss << count;
            ss >> section;

            decal.scale = getFloat("scale", 1.0F, section, path);
            decal.name = getString("name", "", section, path);
            decal.model = ("resources\\images\\" + getString("model", "", section, path));

            v.push_back(decal);
            ss.str("");
            ss.clear();
        }
    }
    catch(...)
    {
        std::cout << "error";
    }
    return v;
}
std::vector<ParticleType> Config::getParticles()
{
    std::vector<ParticleType> v;
    ParticleType particle;
    std::stringstream ss;
    char* path = "resources\\ini\\particles.ini";
    std::cout << "Particles: " << getInt("number", 1, "init", path) << std::endl;
    char section[32];
    try{
        for(int count = 1; count <= getInt("number", 1, "init", path); count++)
        {
            ss << "Particle";
            ss << count;
            ss >> section;

            particle.scale = getFloat("scale", 1.0F, section, path);
            particle.name = getString("name", "", section, path);
            particle.model = ("resources\\images\\" + getString("model", "", section, path));
            particle.duration = getFloat("duration", 1.0F, section, path);

            v.push_back(particle);
            ss.str("");
            ss.clear();
        }
    }
    catch(...)
    {
        std::cout << "error";
    }
    return v;
}

std::vector<WaveType> Config::getWaves()
{
    std::vector<WaveType> v;
    WaveType wave;
    std::stringstream ss;
    std::stringstream ss2;
    char* path = "resources\\ini\\waves.ini";
    std::cout << "Waves: " << getInt("number", 1, "init", path) << std::endl;
    char section[32];
    char section2[32];
    try{
        for(int i = 1; i <= getInt("number", 1, "init", path); i++)
        {
            ss << "Wave";
            ss << i;
            ss >> section;

            wave.total = getInt("numberofenemys", 1, section, path);
            wave.types = getInt("typesofenemys", 1, section, path);

            for(int j = 1; j <= getInt("number", 1, section, path); ++j)
            {
                ss2 << "Enemy";
                ss2 << j;
                ss2 >> section2;

                wave.enemys.push_back(getString(section2, "", section, path));

                ss2.str("");
                ss2.clear();
            }

            v.push_back(wave);
            ss.str("");
            ss.clear();
        }
    }
    catch(...)
    {
        std::cout << "error";
    }
    return v;
}

int Config::getInt(char* key, int defaultValue, char* category, char* fileName)
{
    return GetPrivateProfileInt(category, key, defaultValue, fileName);
}

float Config::getFloat(char* key, float defaultValue, char* category, char* fileName)
{
    char result[255];
    char default_v[255];
    float fltResult;
    sprintf(default_v, "%f",defaultValue);
    GetPrivateProfileString(category, key, default_v, result, 255, fileName);
    fltResult =  atof(result);
    return fltResult;
}

bool Config::getBool(char* key, bool defaultValue, char* category, char* fileName)
{
    char result[255];
    char default_v[255];
    sprintf(default_v, "%s", defaultValue? "True" : "False");
    GetPrivateProfileString(category, key, default_v, result, 255, fileName);
    return (strcmp(result, "True") == 0 || strcmp(result, "true") == 0) ? true : false;
}

std::string Config::getString(char* key, const char* defaultValue, char* category, char* fileName)
{
    std::string temp;
    std::stringstream ss;
    char* result = new char[255];
    memset(result, 0x00, 255);
    GetPrivateProfileString(category, key, defaultValue, result, 255, fileName);
    ss << result;
    ss >> temp;
    return temp;
}
