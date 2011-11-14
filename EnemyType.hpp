#include "TemplateType.hpp"
#include <string>
#ifndef ENEMYTYPEqqq
#define ENEMYTYPEqqq
class EnemyType: public TemplateType
{
public:
    int maxHp, dmg;
    float speed;
    std::string weapon, projectile, decal, particle, sound;
};
#endif
