#include "TemplateType.hpp"
#include <string>
#ifndef ENEMYTYPEqqq
#define ENEMYTYPEqqq
class EnemyType: public TemplateType
{
public:
    int maxHp;
    float speed;
    std::string weapon;
    std::string projectile;
    std::string decal;
    std::string particle;
};
#endif
