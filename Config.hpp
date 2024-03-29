#include "EnemyType.hpp"
#include "WeaponType.hpp"
#include "ProjectileType.hpp"
#include "PowerUpType.hpp"
#include "DecalType.hpp"
#include "ParticleType.hpp"
#include "WaveType.hpp"
#include <vector>
#include <string>
#ifndef CONFIGqqq
#define CONFIGqqq
class Config
{
public:
    std::vector<EnemyType> getEnemys();
    std::vector<ProjectileType> getProjectiles();
    std::vector<WeaponType> getWeapons();
    std::vector<PowerUpType> getPowerUps();
    std::vector<DecalType> getDecals();
    std::vector<ParticleType> getParticles();
    std::vector<WaveType> getWaves();

    int getInt(char* key, int defaultValue, char* category, char* fileName);
    float getFloat(char* key, float defaultValue, char* category, char* fileName);
    bool getBool(char* key, bool defaultValue, char* category, char* fileName);
    std::string getString(char* key, const char* defaultValue, char* category, char* fileName);

    void setInt(char* key, int value, char* category, char* fileName);
    void setFloat(char* key, float value, char* category, char* fileName);
    void setBool(char* key, bool value, char* category, char* fileName);
    void setString(char* key, char* value, char* category, char* fileName);
};
#endif
