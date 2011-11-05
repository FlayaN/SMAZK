#include <vector>
#include <algorithm>
#include <iterator>
#include <SFML/Graphics.hpp>

#include "EnemyType.hpp"
#include "Projectile.hpp"
#include "ParticleType.hpp"
#include "DecalType.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "Config.hpp"
#include "Storage.hpp"
#include "Particle.hpp"
#include "Decal.hpp"

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef GAMEqqq
#define GAMEqqq

class Game
{
public:
    Game(sf::RenderWindow& window);

    void run();
    void draw();
    void updateGameState();
    float calcAngle(sf::Vector2f p1, sf::Vector2f p2);
    float calcDistance(sf::Vector2f p1,sf::Vector2f p2);
    sf::Vector2f calcDistanceV(sf::Vector2f p1,sf::Vector2f p2);
    void moveEntities();
    void collide();
    void updateTimers();
    void killObjects();
    void attack();
    void generateParticle(sf::Vector2f pos, float rot, ParticleType pt);
    void generateDecal(Enemy& enemy, DecalType dt);
    void initStorage();
private:

    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;
    std::vector<Weapon> weapons;
    std::vector<Particle> particles;
    std::vector<Decal> decals;
    Player player;
    Storage storage;

    sf::Clock clock;
    float elapsedTime, gameTime;

    sf::RenderWindow& window;
    sf::Event event;
    sf::Sprite crosshair, bg;

    Config config;

    sf::Image playerImg,crosshairImg,PBulletImg, bgImg;
};
#endif
