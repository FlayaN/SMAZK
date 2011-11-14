#include "EnemyType.hpp"
#include "ProjectileType.hpp"
#include "ParticleType.hpp"
#include "WeaponType.hpp"
#include "DecalType.hpp"
#include "WaveType.hpp"
#include "PowerUpType.hpp"
#include "SFML/Graphics.hpp"

#include <string>
#include <map>
#include <ctime>

#ifndef STORAGEqqq
#define STORAGEqqq

class Storage
{
public:
    static Storage& getInstance();
    //~Storage();

    EnemyType getEnemyType(int index);
    EnemyType getEnemyType(std::string name);
    void setEnemyTypes(std::vector<EnemyType> v);

    ProjectileType getProjectileType(int index);
    ProjectileType getProjectileType(std::string name);
    void setProjectileTypes(std::vector<ProjectileType> v);

    ParticleType getParticleType(int index);
    ParticleType getParticleType(std::string name);
    void setParticleTypes(std::vector<ParticleType> v);

    WeaponType getWeaponType(int index);
    WeaponType getWeaponType(std::string name);
    void setWeaponTypes(std::vector<WeaponType> v);

    DecalType getDecalType(int index);
    DecalType getDecalType(std::string name);
    void setDecalTypes(std::vector<DecalType> v);

    PowerUpType getPowerUpType(int index);
    PowerUpType getPowerUpType(std::string name);
    void setPowerUpTypes(std::vector<PowerUpType> v);

    WaveType getWaveType(int index);
    void setWaveTypes(std::vector<WaveType> v);

    void setImages();
    sf::Image& getImage(std::string name);

    void setSound(bool sound);
    bool isSoundOn();

    float getRandom(float begin, float end);
    int getRandom(int begin, int end);

    void resetStorage();

private:
    Storage();

    Storage(Storage const& copy);
    Storage& operator=(Storage const& copy);

    std::vector<EnemyType> enemies;
    std::vector<ProjectileType> projectiles;
    std::vector<ParticleType> particles;
    std::vector<WeaponType> weapons;
    std::vector<DecalType> decals;
    std::vector<WaveType> waves;
    std::vector<PowerUpType> powerups;

    std::map<std::string, sf::Image> imagemap;

    sf::Randomizer random;
    bool sound;
};
#endif
