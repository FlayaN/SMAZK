#include "TemplateType.hpp"
#include <string>
#ifndef WEAPONTYPEqqq
#define WEAPONTYPEqqq
class WeaponType : public TemplateType
{
public:
    int ammo;
    std::string projectile;
    float speed;
};
#endif
