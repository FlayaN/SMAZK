#include <string>
#include "MovingEntity.hpp"
#include "EnemyType.hpp"

#ifndef ENEMYqqq
#define ENEMYqqq

class Enemy : public MovingEntity
{
public:
    Enemy(EnemyType enemytype, sf::Vector2f pos)
    : MovingEntity(enemytype, pos), hp(enemytype.maxHp){}

    int getHp();
    void setHp(int hp);

private:
    int hp;
};
#endif
