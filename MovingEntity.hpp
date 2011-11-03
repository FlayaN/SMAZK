#include <SFML/Graphics.hpp>
#include <string>

#ifndef MOVEINGENTITYdef
#define MOVEINGENTITYdef

class MovingEntity : public sf::Sprite
{
public:
    MovingEntity(float speed=10, std::string name = "noname") : speed(speed), name(name) {}

    //virtual int getHp() = 0;
    //virtual void setHp(int hp) = 0;

    float getSpeed();
    void setSpeed(float speed);

    std::string getName();
    void setName(std::string name);

private:
    float speed;
    std::string name;
};
#endif
