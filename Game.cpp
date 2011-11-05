#include "Game.hpp"


#define PI 3.14159265
#define sqrt2 1.41421356
#define sqrt2inv 0.707106781
#define SCREEN_SIZE_WIDTH   1280
#define SCREEN_SIZE_HEIGHT  720


Game::Game(sf::RenderWindow& window)
    : window(window)
{
    playerImg.LoadFromFile("resources\\images\\Anders.png");
    crosshairImg.LoadFromFile("resources\\images\\crosshair.png");
    PBulletImg.LoadFromFile("resources\\images\\PBullet.png");
    bgImg.LoadFromFile("resources\\images\\floor.png");
    bg.SetImage(bgImg);
    window.ShowMouseCursor(false);
    gameTime=0;
    initStorage();
}

void Game::initStorage()
{
    Storage& storage = Storage::getInstance();
    storage.setEnemyTypes(config.getEnemys());
    storage.setProjectileTypes(config.getProjectiles());
    storage.setParticleTypes(config.getParticles());
    storage.setWeaponTypes(config.getWeapons());
    storage.setDecalTypes(config.getDecals());
    storage.setPowerUpTypes(config.getPowerUps());
    storage.setWaveTypes(config.getWaves());
    storage.setImages();

    srand((unsigned) time(0));
    for (int i = 0; i < 50; ++i)
    {
        enemies.push_back(Enemy(storage.getEnemyType(0)));
        enemies[i].SetPosition((rand() % SCREEN_SIZE_WIDTH),(rand() % SCREEN_SIZE_HEIGHT));
        enemies[i].SetCenter(storage.getImage("zombie").GetWidth()/2, storage.getImage("zombie").GetHeight()/2);
    }

    for (int i = 50; i < 100; ++i)
    {
        enemies.push_back(Enemy(storage.getEnemyType(1)));
        enemies[i].SetPosition((rand() % SCREEN_SIZE_WIDTH),(rand() % SCREEN_SIZE_HEIGHT));
        enemies[i].SetCenter(storage.getImage("zombie").GetWidth()/2, storage.getImage("zombie").GetHeight()/2);
    }

    player = Player(3.0f, 100,Weapon(storage.getWeaponType(0)));
    player.SetImage(playerImg);
    player.SetPosition(500.0f,300.0f);
    player.SetCenter(playerImg.GetWidth()/2,playerImg.GetHeight()/2);

    crosshair.SetImage(crosshairImg);
    crosshair.SetCenter(crosshairImg.GetWidth()/2,crosshairImg.GetHeight()/2);
}

void Game::run()
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

void Game::draw()
{
    window.Clear();
    //for_each(enemies.begin(),enemies.end(),window.Draw);
    window.Draw(bg);
    for (unsigned int i = 0; i < decals.size(); ++i)
    {
        window.Draw(decals[i]);
    }
    for (unsigned int i = 0; i < enemies.size(); ++i)
    {
        window.Draw(enemies[i]);
    }
    for (unsigned int i = 0; i < projectiles.size(); ++i)
    {
        window.Draw(projectiles[i]);
    }
    for (unsigned int i = 0; i < particles.size(); ++i)
    {
        window.Draw(particles[i]);
    }
    window.Draw(player);
    window.Draw(crosshair);

    window.Display();
}

void Game::updateGameState()
{
    elapsedTime=clock.GetElapsedTime();
    gameTime += elapsedTime;
    clock.Reset();

    moveEntities();
    attack();
    collide();
    updateTimers();
    killObjects();
}

void Game::moveEntities()
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
    for (unsigned int i = 0; i < particles.size(); ++i)
    {
        float speed = particles[i].getSpeed();//*0.1;
        float rotation = -(particles[i].GetRotation()/180*PI)+PI/2;
        float dx = speed*std::cos(rotation);
        float dy = speed*std::sin(rotation);
        //projectiles[i].SetRotation((-rotation*180/PI)-90);
        particles[i].Move(dx,dy);
    }
    //moves the player
    float dx = 0;
    float dy = 0;
    float bordercollisionX = player.GetSize().x * sqrt2inv;
    float bordercollisionY = player.GetSize().y * sqrt2inv;

    if((window.GetInput().IsKeyDown(sf::Key::Up) || window.GetInput().IsKeyDown(sf::Key::W) ) && player.GetPosition().y - bordercollisionY > 0)
    {
        --dy;
    }
    if((window.GetInput().IsKeyDown(sf::Key::Down) || window.GetInput().IsKeyDown(sf::Key::S) ) && player.GetPosition().y + bordercollisionY < SCREEN_SIZE_HEIGHT)
    {
        ++dy;
    }
    if((window.GetInput().IsKeyDown(sf::Key::Left) || window.GetInput().IsKeyDown(sf::Key::A) ) && player.GetPosition().x - bordercollisionX > 0)
    {
        --dx;
    }
    if((window.GetInput().IsKeyDown(sf::Key::Right) || window.GetInput().IsKeyDown(sf::Key::D) ) && player.GetPosition().x + bordercollisionX < SCREEN_SIZE_WIDTH)
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

void Game::attack()
{
    if(window.GetInput().IsMouseButtonDown(sf::Mouse::Left) && player.getWeapon().isAttackReady())
    {
        player.attack();
        Projectile tmp_projectile = Projectile(Storage::getInstance().getProjectileType(0));
        tmp_projectile.SetPosition(player.GetPosition());
        tmp_projectile.SetRotation(player.GetRotation());
        projectiles.push_back(tmp_projectile);
    }
}

void Game::collide()
{

    //Enemies - Player
    for (unsigned int i = 0; i < enemies.size(); ++i)
    {
        sf::Vector2f v = calcDistanceV(enemies[i].GetPosition(),player.GetPosition());
        if (v.x <= (player.GetSize().x+enemies[i].GetSize().x)/2 && v.y <= (player.GetSize().y+enemies[i].GetSize().y)/2) //if the distance in x and y are less than the size of player+enemie/2 cause both player and enemy has a size.
        {
            if ( player.getHp() <= 0) std::cout << "";
            player.setHp(player.getHp()-1);
            //std::cout << player.getHp() << std::endl;
        }
        for(unsigned int j = 0; j < projectiles.size(); ++j)
        {
            v = calcDistanceV(enemies[i].GetPosition(),projectiles[j].GetPosition());
            if(v.x <= (projectiles[j].GetSize().x+enemies[i].GetSize().x)/2 && v.y <= (projectiles[j].GetSize().y+enemies[i].GetSize().y)/2)
            {
                enemies[i].setHp(enemies[i].getHp()-projectiles[j].getDmg());
                //std::cout << enemies[i].getHp() << std::endl;
                generateParticle(projectiles[j].GetPosition(),projectiles[j].GetRotation(), Storage::getInstance().getParticleType(0));
                projectiles[j].setDead();
                if(enemies[i].getHp() <= 0)
                {
                    enemies[i].setDead();
                    generateDecal(enemies[i], Storage::getInstance().getDecalType(1));
                }
            }
        }
    }
}

void Game::updateTimers()
{
    player.updateTimers(elapsedTime);
    for(unsigned int i = 0; i < particles.size(); ++i)
    {
        particles[i].updateTimers(elapsedTime);
    }

}

void Game::killObjects()
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
    particles.erase(std::remove_if(particles.begin(),particles.end(),movingEntity::isDead),particles.end());
}

void Game::generateParticle(sf::Vector2f pos, float rot, ParticleType pt)
{
    int random = rand() % 20;
    for (int i = 0; i < random; ++i)
    {
        Particle tmp_particle = Particle(pt, (rand() % 500)/100 + 2);
        tmp_particle.SetPosition(pos);
        tmp_particle.SetRotation(rot-10+(rand() % 1000)/300);
        particles.push_back(tmp_particle);
    }

}

void Game::generateDecal(Enemy& enemy, DecalType dt)
{
    Decal tmp_decal = Decal(dt);
    tmp_decal.SetPosition(enemy.GetPosition());
    tmp_decal.SetCenter(tmp_decal.GetSize().x/2, tmp_decal.GetSize().y/2);
    tmp_decal.SetScale(enemy.GetScale());
    tmp_decal.SetRotation(enemy.GetRotation());
    decals.push_back(tmp_decal);
}

float Game::calcAngle(sf::Vector2f p1, sf::Vector2f p2)//float x1, float y1, float x2,float y2)
{
    return std::atan2((p2.x-p1.x),(p1.y-p2.y));
}

float Game::calcDistance(sf::Vector2f p1,sf::Vector2f p2)
{
    return std::sqrt(std::pow((p1.x-p2.x),2)+std::pow(p1.y-p2.y,2));
}

sf::Vector2f Game::calcDistanceV(sf::Vector2f p1,sf::Vector2f p2)
{
    return sf::Vector2f(std::abs(p1.x-p2.x),std::abs(p1.y-p2.y));
}
