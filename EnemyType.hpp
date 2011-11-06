#include "TemplateType.hpp"
#include <string>
#ifndef ENEMYTYPEqqq
#define ENEMYTYPEqqq
class EnemyType: public TemplateType
{
public:
    int maxHp;
    float speed;
    std::string weapon, projectile, decal, particle, sound, dmg;
};
#endif
