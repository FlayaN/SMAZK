#include "EnemyType.hpp"
#include "ProjectileType.hpp"
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

    /*WeaponType getWeaponType(int index)
    void addWeaponType(std::vector<WeaponType>)

    PowerUpType getPowerUpType(int index)
    void addPowerUpType(std::vector<PowerUpType>)

    DecalType getDecalType(int index)
    void addDecalType(std::vector<DecalType>)

    ParticleType getParticleType(int index)
    void addParticleType(std::vector<ParticleType>)*/

    void setImages();
    sf::Image& getImage(std::string name);
private:
    std::vector<EnemyType> enemys;
    std::vector<ProjectileType> projectiles;
    /*std::vector<WeaponType> weapons
    std::vector<PowerUpType> powerups
    std::vector<DecalType> decals
    std::vector<ParticleType> particles*/

    std::map<std::string, sf::Image> imagemap;

};
