#ifndef CONFIG_H
#define CONFIG_H
class Config
{
public:
    //Config(char* fileName, char* Category);
    vector<EnemyType> getEnemys();
    vector<ProjectileType> getProjectiles();
    vector<WeaponType> getWeapons();
    vector<PowerUpType> getPowerUps();
    vector<DecalType> getDecals();
    vector<ParticleType> getParticles();
    void initConfig(char* filename);
    int getInt(char* Key, int DefaultValue);
    float getFloat(char* Key, float DefaultValue);
    bool getBool(char* Key, bool DefaultValue);
    char* getString(char* Key, const char* DefaultValue);

private:

    char* fileName = "";
    char* category = "";
}
#endif
