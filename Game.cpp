#include <vector>
#include <algorithm>
#include <iterator>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player.hpp"
#include <cmath>
#include <iostream>


#define PI 3.14159265
#define sqrt2 1.41421356
#define sqrt2inv 0.707106781
class Game
{
    private:

    std::vector<Enemy> enemies;
    Player player;

    sf::Clock clock;
    double elapseTime;
    sf::RenderWindow& window;
    sf::Event event;
    sf::Sprite crosshair;
    //sf::Sprite crosshair;
     //används för att få info om input, ex) input.getmouse(x)

    //image
    sf::Image playerImg,zombieImg,crosshairImg;

    public:
    Game(sf::RenderWindow& window) : window(window)
    {
        playerImg.LoadFromFile("resources\\images\\Anders.png");
        zombieImg.LoadFromFile("resources\\images\\zombie.png");
        crosshairImg.LoadFromFile("resources\\images\\crosshair.png");
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
            moveEntities();
        }
    }
    //void playSounds() {}

    void draw()
    {
        window.Clear(sf::Color(200, 0, 0));
        //for_each(enemies.begin(),enemies.end(),window.Draw);

        for (unsigned int i = 0; i < enemies.size(); ++i)
        {
                window.Draw(enemies[i]);
        }
        window.Draw(player);
        window.Draw(crosshair);

        window.Display();
    }

    void updateGameState()
    {
        elapseTime=clock.GetElapsedTime();
        clock.Reset();
    }

    float calcAngle(float x1, float y1, float x2,float y2)
    {
        return std::atan2((x2-x1),(y1-y2));
    }

    void moveEntities()
    {
        for (unsigned int i = 0; i < enemies.size(); ++i)
        {
                float speed = enemies[i].getSpeed();//*0.1;
                float rotation = (calcAngle(player.GetPosition().x,player.GetPosition().y,enemies[i].GetPosition().x,enemies[i].GetPosition().y))+PI/2;
                float dx = speed*std::cos(rotation);
                float dy = speed*std::sin(rotation);
                enemies[i].SetRotation((-rotation*180/PI)-90);
                enemies[i].Move(dx,dy);
        }
        //moves the player
        float dx = 0;
        float dy = 0;
        if(window.GetInput().IsKeyDown(sf::Key::Up))// || window.GetInput().IsKeyDown(sf::Key::W))
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
        player.Move(dx*player.getSpeed(),dy*player.getSpeed());
    }


    //void collide() {}
    //void killObjekt() {}
    //Storage& initStorage(Storage&) {}
     void initStorage()
     {
        enemies.push_back(Enemy(1.5f, 10, "zombie"));
        enemies[0].SetImage(zombieImg);
        enemies[0].Rotate(123);
        enemies[0].SetPosition(400.0f,300.0f);
        enemies[0].SetCenter(zombieImg.GetWidth()/2,zombieImg.GetHeight()/2);

        player = Player(3.0f, 100);
        player.SetImage(playerImg);
        player.SetPosition(500.0f,300.0f);
        player.SetCenter(playerImg.GetWidth()/2,playerImg.GetHeight()/2);

        crosshair.SetImage(crosshairImg);
        crosshair.SetCenter(crosshairImg.GetWidth()/2,crosshairImg.GetHeight()/2);

     }


};
