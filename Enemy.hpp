#include <string>
#include "MovingEntity.hpp"
#include "EnemyType.hpp"
#include "Sound.hpp"

#ifndef ENEMYqqq
#define ENEMYqqq

class Enemy : public MovingEntity, public Sound
{
public:
    Enemy(EnemyType enemytype, sf::Vector2f pos)
    : MovingEntity(enemytype, pos), Sound(enemytype.sound), hp(enemytype.maxHp), decal(enemytype.decal){}

    int getHp();
    void setHp(int hp);

    std::string getDecal();
private:
    int hp;
    std::string decal;
};
#endif
