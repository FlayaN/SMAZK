#include "MovingEntity.hpp"

class Player : public MovingEntity
{
  public:

    Player(){}

  Player(float speed, int health)
  : MovingEntity(speed), health(health) {}

  protected:

  int getHealth();

  void setHealth(int health);

  private:

  int health;
};
