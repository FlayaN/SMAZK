#include "TemplateType.hpp"
#include <string>
#ifndef POWERUPTYPEqqq
#define POWERUPTYPEqqq
class PowerUpType : public TemplateType
{
public:
    float damageScale;
    float speedScale;
    int heal;
    std::string sound;
    bool instant;
};
#endif
