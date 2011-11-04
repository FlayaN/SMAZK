#include <vector>
#include <algorithm>
#include <iterator>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "EnemyType.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "Projectile.hpp"
#include "Config.hpp"
#include "Storage.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>


#define PI 3.14159265
#define sqrt2 1.41421356
#define sqrt2inv 0.707106781
#define SCREEN_SIZE_WIDTH   1280
#define SCREEN_SIZE_HEIGHT  720
class Game
{
    private:

    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;
    std::vector<Weapon> weapons;
    Player player;
    Storage storage;

    sf::Clock clock;
    double elapseTime;
    sf::RenderWindow& window;
    sf::Event event;
    sf::Sprite crosshair;
    sf::Sprite bg;

    Config config;
     //används för att få info om input, ex) input.getmouse(x)

    //image
    sf::Image playerImg,crosshairImg,PBulletImg, bgImg;

    public:
    Game(sf::RenderWindow& window) : window(window)
    {
        playerImg.LoadFromFile("resources\\images\\Anders.png");
        crosshairImg.LoadFromFile("resources\\images\\crosshair.png");
        PBulletImg.LoadFromFile("resources\\images\\PBullet.png");
        bgImg.LoadFromFile("resources\\images\\floor.png");
        bg.SetImage(bgImg);
        window.ShowMouseCursor(false);
        initStorage();
    }

    void run()
    {
        while (window.IsOpened())
        {
            draw();
            while (window.GetEvent(event)) //Have to exist to update inputs
            {
                if (event.Type == sf::Event::Closed)
                    window.Close();
            }
            updateGameState();

        }
    }
    //void playSounds() {}

    void draw()
    {
        window.Clear();
        //for_each(enemies.begin(),enemies.end(),window.Draw);
        window.Draw(bg);
        for (unsigned int i = 0; i < enemies.size(); ++i)
        {
            if(!enemies[i].isDead())
                window.Draw(enemies[i]);
        }
        for (unsigned int i = 0; i < projectiles.size(); ++i)
        {
            if(!projectiles[i].isDead())
                window.Draw(projectiles[i]);
        }
        window.Draw(player);
        window.Draw(crosshair);

        window.Display();
    }

    void updateGameState()
    {
        elapseTime=clock.GetElapsedTime();
        clock.Reset();

        moveEntities();
        attack();
        collide();
        killObjects();
    }


    float calcAngle(sf::Vector2f p1, sf::Vector2f p2)//float x1, float y1, float x2,float y2)
    {
        return std::atan2((p2.x-p1.x),(p1.y-p2.y));
    }

    float calcDistance(sf::Vector2f p1,sf::Vector2f p2)
    {
        return std::sqrt(std::pow((p1.x-p2.x),2)+std::pow(p1.y-p2.y,2));
    }

    sf::Vector2f calcDistanceV(sf::Vector2f p1,sf::Vector2f p2)
    {
        return sf::Vector2f(std::abs(p1.x-p2.x),std::abs(p1.y-p2.y));
    }

    void moveEntities()
    {
        //Moves Enemies
        for (unsigned int i = 0; i < enemies.size(); ++i)
        {
                float speed = enemies[i].getSpeed();//*0.1;
                float rotation = (calcAngle(player.GetPosition(),enemies[i].GetPosition()))+PI/2;
                float dx = speed*std::cos(rotation);
                float dy = speed*std::sin(rotation);
                enemies[i].SetRotation((-rotation*180/PI)-90);
                enemies[i].Move(dx,dy);
        }
        //Moves Projectiles
        for (unsigned int i = 0; i < projectiles.size(); ++i)
        {
                float speed = projectiles[i].getSpeed();//*0.1;
                float rotation = -(projectiles[i].GetRotation()/180*PI)+PI/2;
                float dx = speed*std::cos(rotation);
                float dy = speed*std::sin(rotation);
                //projectiles[i].SetRotation((-rotation*180/PI)-90);
                projectiles[i].Move(dx,dy);
        }
        //moves the player
        float dx = 0;
        float dy = 0;
        if(window.GetInput().IsKeyDown(sf::Key::Up) || window.GetInput().IsKeyDown(sf::Key::W))
        {
            --dy;
        }
        if(window.GetInput().IsKeyDown(sf::Key::Down) || window.GetInput().IsKeyDown(sf::Key::S))
        {
            ++dy;
        }
        if(window.GetInput().IsKeyDown(sf::Key::Left) || window.GetInput().IsKeyDown(sf::Key::A))
        {
            --dx;
        }
        if(window.GetInput().IsKeyDown(sf::Key::Right) || window.GetInput().IsKeyDown(sf::Key::D))
        {
            ++dx;
        }
        crosshair.SetPosition(window.GetInput().GetMouseX(),window.GetInput().GetMouseY());
        if(dx != 0 && dy != 0)
        {
            dx *= sqrt2inv;
            dy *= sqrt2inv;
        }

        // Rotate the player to the crosshair
        player.Move(dx*player.getSpeed(),dy*player.getSpeed());;
        //sf::Vector2f mouse(window.GetInput().GetMouseX(),window.GetInput().GetMouseY());
        float rotation = (calcAngle(player.GetPosition(),sf::Vector2f(window.GetInput().GetMouseX(),window.GetInput().GetMouseY())))+PI/2;
        player.SetRotation((-rotation*180/PI)-90);

    }


    void collide() {

        //Enemies - Player
        for (unsigned int i = 0; i < enemies.size(); ++i)
        {
            sf::Vector2f v = calcDistanceV(enemies[i].GetPosition(),player.GetPosition());
            if (v.x <= (player.GetSize().x+enemies[i].GetSize().x)/2 && v.y <= (player.GetSize().y+enemies[i].GetSize().y)/2) //if the distance in x and y are less than the size of player+enemie/2 cause both player and enemy has a size.
            {
                if ( player.getHp() <= 0) std::cout << "You are now dead" << std::endl;
                player.setHp(player.getHp()-1);
                //std::cout << player.getHp() << std::endl;
            }
            for(unsigned int j = 0; j < projectiles.size(); ++j)
            {
                v = calcDistanceV(enemies[i].GetPosition(),projectiles[j].GetPosition());
                if(v.x <= (projectiles[j].GetSize().x+enemies[i].GetSize().x)/2 && v.y <= (projectiles[j].GetSize().y+enemies[i].GetSize().y)/2)
                {
                    enemies[i].setHp(enemies[i].getHp()-1);
                    //std::cout << enemies[i].getHp() << std::endl;
                    projectiles[j].setDead();
                    if(enemies[i].getHp() <= 0) enemies[i].setDead();
                }
            }
        }
    }

    void killObjects()
    {
        for(unsigned int i = 0; i < projectiles.size(); ++i)
        {
            if(projectiles[i].GetPosition().x <= 0 || projectiles[i].GetPosition().x >= SCREEN_SIZE_WIDTH || projectiles[i].GetPosition().y <= 0 || projectiles[i].GetPosition().y >= SCREEN_SIZE_HEIGHT)
            {
                projectiles[i].setDead();
            }
        }
        projectiles.erase(std::remove_if(projectiles.begin(),projectiles.end(),movingEntity::isDead),projectiles.end());
        enemies.erase(std::remove_if(enemies.begin(),enemies.end(),movingEntity::isDead),enemies.end());
    }

    void attack()
    {
        if(window.GetInput().IsMouseButtonDown(sf::Mouse::Left))// && player.getWeapon().isAttackReady())
        {
            Projectile tmp_projectile = Projectile(storage.getProjectileType(0), storage.getImage("PBullet"));
            tmp_projectile.SetPosition(player.GetPosition());
            tmp_projectile.SetRotation(player.GetRotation());
            projectiles.push_back(tmp_projectile);
        }
    }
    //void killObjekt() {}
    //Storage& initStorage(Storage&) {}
    void initStorage()
    {

        storage.setEnemyTypes(config.getEnemys());
        storage.setProjectileTypes(config.getProjectiles());
        storage.setImages();

        srand((unsigned) time(0));
        std::cout << rand() << std::endl;
        for (int i = 0; i < 10; i++)
        {
            enemies.push_back(Enemy(storage.getEnemyType(0), storage.getImage("zombie")));
            enemies[i].SetPosition((rand() % 800),(rand() % 600));
            enemies[i].SetCenter(storage.getImage("zombie").GetWidth()/2,storage.getImage("zombie").GetHeight()/2);
        }

        player = Player(3.0f, 100,Weapon(3,"Pistol","PBullet"));
        player.SetImage(playerImg);
        player.SetPosition(500.0f,300.0f);
        player.SetCenter(playerImg.GetWidth()/2,playerImg.GetHeight()/2);

        crosshair.SetImage(crosshairImg);
        crosshair.SetCenter(crosshairImg.GetWidth()/2,crosshairImg.GetHeight()/2);
    }

};
