#include <SFML/Graphics.hpp>
#include <string>

#ifndef MOVEINGENTITYdef
#define MOVEINGENTITYdef

class MovingEntity : public sf::Sprite
{
public:
    MovingEntity(float speed=10, std::string name = "noname") : speed(speed), name(name) {}

    virtual int getHealth() = 0;
    virtual void setHealth(int health) = 0;

    float getSpeed();
    void setSpeed(float speed);

    std::string getName();
    void setName(std::string name);

private:
    float speed;
    std::string name;
};
#endif
