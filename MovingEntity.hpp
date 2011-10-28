#include <SFML/Graphics.hpp>

#ifndef MOVEINGENTITYdef
#define MOVEINGENTITYdef

class MovingEntity : public sf::Sprite
{
    public:
        //virtual ~MovingEntity() = 0;
        MovingEntity(float speed=10) : speed(speed) {}

        virtual int getHealth() = 0;
        virtual void setHealth(int health) = 0;

        float getSpeed();
        void setSpeed(float speed);
    protected:
        //return the current speed


        //set the current speed


    private:
        float speed;
};


#endif
