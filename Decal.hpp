#include <string>
#include "StillObject.hpp"
#include "DecalType.hpp"

#ifndef DECALqqq
#define DECALqqq

class Decal : public StillObject
{
public:
    Decal(){}

    Decal(DecalType decaltype)
    : StillObject(decaltype) {}

private:

};

#endif

