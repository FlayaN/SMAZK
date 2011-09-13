#include <string>

class Enemy : public MovingEntity
{
public:

    Enemy(float speed,int health=100,std::string type="zombie")
    : MovingEntity(speed), health(health), type(type) {}

protected:

    int getHealth();
    void setHealth(int health);

private:

    std::string type;
    int health;
};
