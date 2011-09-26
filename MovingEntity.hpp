#include <SFML/Graphics.hpp>

class MovingEntity : public sf::Sprite
{
    public:

        virtual ~MovingEntity() = 0;
        MovingEntity(float speed=10) : speed(speed) {}

        virtual getHealth() = 0;
        virtual setHealth(int health) = 0;

    protected:

        //return the current speed
        float getSpeed()
        {
            return this.speed;
        }

        //set the current speed
        void setSpeed(float speed)
        {
            this.speed = speed;
        }

    private:

        float speed;
};
