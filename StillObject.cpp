#include <string>
#include "StillObject.hpp"

std::string StillObject::getName()
{
    return name;
}

void StillObject::setName(std::string name)
{
    this->name = name;
}
