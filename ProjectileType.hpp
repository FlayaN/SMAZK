#include "TemplateType.hpp"
#include <string>
#ifndef PROJECTILETYPEqqq
#define PROJECTILETYPEqqq
class ProjectileType : public TemplateType
{
public:
    float speed;
    int damage;
    std::string particle;
    bool piercing;
};
#endif
