#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "EnemyType.hpp"
#include "Projectile.hpp"
#include "ParticleType.hpp"
#include "DecalType.hpp"
#include "WaveType.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "Config.hpp"
#include "Storage.hpp"
#include "Particle.hpp"
#include "Decal.hpp"
#include "Utility.hpp"
#include "PowerUp.hpp"

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>

#ifndef GAMEqqq
#define GAMEqqq

class Game
{
public:
    Game(sf::RenderWindow& window);
    ~Game();
    void initStorage();
    bool run();
    void draw();
    void updateGameState();
    void spawn();
    void moveEntities();
    void attack();
    void collide();
    void updateTimers();
    void killObjects();
    void highScore(int score);

    void generateBloodParticle(sf::Vector2f pos, float rot, ParticleType pt);
    void generateShellParticle(sf::Vector2f pos, float rot, ParticleType pt);
    void generateDecal(Enemy& enemy, DecalType dt);

private:

    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;
    std::vector<Weapon> weapons;
    std::vector<Particle> particles;
    std::vector<Decal> decals;
    std::vector<PowerUp> powerups;

    Player player;
    Config config;
    int waves, currWave, frameHelp, gameScore;
    float elapsedTime, gameTime, frameTime;
    bool finished, victory;

    sf::Clock clock;
    sf::Font font;
    sf::String scoreText, ammoText, fpsText, waveText, enemysText, victoryText;
    sf::RenderWindow& window;
    sf::Event event;
    sf::Shape playerHp, hpBg;
    sf::Sprite crosshair, bg, hpHud, weaponHud;
    sf::Image playerImg,crosshairImg,PBulletImg, bgImg, hpHudImg, weaponHudImg;
};
#endif
