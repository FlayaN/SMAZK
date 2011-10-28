#include <vector>
#include <algorithm>
#include <iterator>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player.hpp"
#include <cmath>


#define PI 3.14159265
class Game
{
    private:

    std::vector<Enemy> enemies;
    Player player;

    sf::Clock clock;
    double elapseTime;
    sf::RenderWindow& window;

    //image
    sf::Image playerImg,zombieImg;

    public:
    Game(sf::RenderWindow& window) : window(window){

        playerImg.LoadFromFile("resourses\\images\\Anders.png");
        zombieImg.LoadFromFile("resourses\\images\\zombie.png");

        initStorage();
    }

    void run()
    {
        while (true)
        {
            draw();
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

        window.Display();
    }
    //void updateGameState() {}
    void moveEntities()
    {
        for (unsigned int i = 0; i < enemies.size(); ++i)
        {
                float speed = enemies[i].getSpeed()*0.001;
                float rotation = -(enemies[i].GetRotation()+90)*PI/180;
                float dx = speed*std::cos(rotation);
                float dy = speed*std::sin(rotation);
                enemies[i].Move(dx,dy);
        }
    }
    //void collide() {}
    //void killObjekt() {}
    //Storage& initStorage(Storage&) {}
     void initStorage()
     {
        enemies.push_back(Enemy(2, 10, "zombie"));
        enemies[0].SetImage(zombieImg);
        enemies[0].Rotate(123);
        enemies[0].SetPosition(400.0f,300.0f);

        player = Player(1.0f,100);
        player.SetImage(playerImg);
        player.SetPosition(500.0f,300.0f);

     }


};
