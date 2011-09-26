class Player : public MovingEntity
{
  public:

  Player(float speed, int health)
  : MovingEntity(speed), health(health) {}

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

  int health;
};
