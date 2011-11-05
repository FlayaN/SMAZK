#include "EnemyType.hpp"
#include "ProjectileType.hpp"
#include "ParticleType.hpp"
#include "WeaponType.hpp"
#include "DecalType.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include <map>
class Storage
{
public:
    EnemyType getEnemyType(int index);
    void setEnemyTypes(std::vector<EnemyType> v);

    ProjectileType getProjectileType(int index);
    void setProjectileTypes(std::vector<ProjectileType> v);

    ParticleType getParticleType(int index);
    void setParticleTypes(std::vector<ParticleType> v);

    WeaponType getWeaponType(int index);
    void setWeaponTypes(std::vector<WeaponType> v);

    DecalType getDecalType(int index);
    void setDecalTypes(std::vector<DecalType> v);

    /*    PowerUpType getPowerUpType(int index)
    void addPowerUpType(std::vector<PowerUpType>)*/

    void setImages();
    sf::Image& getImage(std::string name);

private:
    std::vector<EnemyType> enemys;
    std::vector<ProjectileType> projectiles;
    std::vector<ParticleType> particles;
    std::vector<WeaponType> weapons;
    std::vector<DecalType> decals;
    /*std::vector<PowerUpType> powerups
    */

    std::map<std::string, sf::Image> imagemap;

};
