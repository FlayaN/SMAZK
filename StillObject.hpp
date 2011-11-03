#include <SFML/Graphics.hpp>
#include <string>
#ifndef STILLOBJECTqqq
#define STILLOBJECTqqq

class StillObject : public sf::Sprite
{
public:
    StillObject(std::string name = "noname") : name(name) {}

    std::string getName();
    void setName(std::string name);

private:
    std::string name;
};

#endif
