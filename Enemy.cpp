#include <string>

class Enemy : public MovingEntity
{
    public:

    Enemy(float speed,int health=100,std::string type="zombie")
    : MovingEntity(speed), health(health), type(type) {}

    protected:

    int getHealth()
    {
        return this.health;
    }
    void setHealth(int health)
    {
        this.health = health;
    }

    private:

    std::string type;
    int health;
};
