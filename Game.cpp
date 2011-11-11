#include "Game.hpp"


#define PI 3.14159265
#define sqrt2 1.41421356
#define sqrt2inv 0.707106781
#define SCREEN_SIZE_WIDTH   1280
#define SCREEN_SIZE_HEIGHT  720


Game::Game(sf::RenderWindow& window)
    : window(window)
{
    playerImg.LoadFromFile("resources\\images\\player.png");
    crosshairImg.LoadFromFile("resources\\images\\crosshair.png");
    bgImg.LoadFromFile("resources\\images\\floor.png");
    font.LoadFromFile("resources\\zombie.ttf");
    gameTime=0;
    currWave=-1;
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

    waves = config.getInt("number", 1, "init", "resources\\ini\\waves.ini");

    player = Player(3.0f, 100,Weapon(storage.getWeaponType(0), sf::Vector2f(player.GetPosition()), player.GetRotation()));
    player.SetImage(playerImg);
    player.SetPosition(500.0f,300.0f);
    player.SetCenter(playerImg.GetWidth()/2,playerImg.GetHeight()/2);

    bg.SetImage(bgImg);

    crosshair.SetImage(crosshairImg);
    crosshair.SetCenter(crosshairImg.GetWidth()/2,crosshairImg.GetHeight()/2);

    text.SetFont(font);
    text.SetSize(50);
    text.SetColor(sf::Color(255, 0, 0, 255));
}

void Game::run()
{
    while (window.GetEvent(event)) //Have to exist to update inputs
    {
        if (event.Type == sf::Event::Closed)
        {
            window.Close();
        }
    }
    draw();
    updateGameState();
}

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
    for (unsigned int i = 0; i < powerups.size(); ++i)
    {
        window.Draw(powerups[i]);
    }
    window.Draw(player);
    window.Draw(crosshair);
    window.Draw(text);

    window.Display();
}

void Game::updateGameState()
{
    elapsedTime=clock.GetElapsedTime();
    gameTime += elapsedTime;
    clock.Reset();
    //text.SetText("Enemys " + Utility::int2Str(enemies.size()));
    text.SetText("Wave " + Utility::int2Str(currWave+1) + " enemys " + Utility::int2Str(enemies.size()) + " playerhp " + Utility::int2Str(player.getHp()));

    spawn();
    moveEntities();
    attack();
    collide();
    updateTimers();
    killObjects();
}

void Game::spawn()
{
    if(enemies.size() == 0 && currWave + 1 < waves)
    {
        ++currWave;
        WaveType tmp_wave = Storage::getInstance().getWaveType(currWave);
        int enemyTypesPerWave = tmp_wave.total/tmp_wave.types;
        for (int i = 0; i < tmp_wave.types; ++i)
        {
            for(int j = 0; j < enemyTypesPerWave; ++j)
            {
                sf::Vector2f pos;

                int randInt = Storage::getInstance().getRandom(0, 3);
                switch(randInt)
                {
                case 0:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(-100, 0), Storage::getInstance().getRandom(0, SCREEN_SIZE_HEIGHT));
                    break;
                case 1:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(SCREEN_SIZE_WIDTH, SCREEN_SIZE_WIDTH+100), Storage::getInstance().getRandom(0, SCREEN_SIZE_HEIGHT));
                    break;
                case 2:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(0, SCREEN_SIZE_WIDTH), Storage::getInstance().getRandom(-100,0));
                    break;
                default:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(0, SCREEN_SIZE_WIDTH),Storage::getInstance().getRandom(SCREEN_SIZE_HEIGHT,SCREEN_SIZE_HEIGHT+100));
                    break;
                }
                enemies.push_back(Enemy(Storage::getInstance().getEnemyType(tmp_wave.enemys[i]), pos));
            }
        }
        int random = Storage::getInstance().getRandom(0, currWave);
        for(unsigned int i = 0; i < random; ++i)
        {
            int randInt = Storage::getInstance().getRandom(0, config.getInt("number", 1, "init", "resources\\ini\\powerups.ini") - 1);
            powerups.push_back(PowerUp(Storage::getInstance().getPowerUpType(randInt), sf::Vector2f(Storage::getInstance().getRandom(0, SCREEN_SIZE_WIDTH), Storage::getInstance().getRandom(0, SCREEN_SIZE_HEIGHT)), 0));
        }
    }
}

void Game::moveEntities()
{
    //Moves Enemies
    for (unsigned int i = 0; i < enemies.size(); ++i)
    {
        float speed = enemies[i].getSpeed();
        float rotation = (Utility::calcAngle(player.GetPosition(),enemies[i].GetPosition()))+PI/2;
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
    float rotation = (Utility::calcAngle(player.GetPosition(),sf::Vector2f(window.GetInput().GetMouseX(),window.GetInput().GetMouseY())))+PI/2;
    player.SetRotation((-rotation*180/PI)-90);

}

void Game::attack()
{
    if(window.GetInput().IsMouseButtonDown(sf::Mouse::Left) && player.getWeapon().isAttackReady())
    {
        player.attack();
        Projectile tmp_projectile = Projectile(Storage::getInstance().getProjectileType(0), sf::Vector2f(player.GetPosition()), player.GetRotation());
        generateShellParticle(tmp_projectile.GetPosition(),tmp_projectile.GetRotation(), Storage::getInstance().getParticleType(2));
        projectiles.push_back(tmp_projectile);
        player.getWeapon().playSound();
    }
}

void Game::collide()
{

    //Enemies - Player
    for (unsigned int i = 0; i < enemies.size(); ++i)
    {
        sf::Vector2f v = Utility::calcDistanceV(enemies[i].GetPosition(),player.GetPosition());
        if (v.x <= (player.GetSize().x+enemies[i].GetSize().x)/2 && v.y <= (player.GetSize().y+enemies[i].GetSize().y)/2) //if the distance in x and y are less than the size of player+enemie/2 cause both player and enemy has a size.
        {
            if ( player.getHp() <= 0) std::cout << "";
            player.setHp(player.getHp()-1);
            //std::cout << player.getHp() << std::endl;
        }
        for(unsigned int j = 0; j < projectiles.size(); ++j)
        {
            v = Utility::calcDistanceV(enemies[i].GetPosition(),projectiles[j].GetPosition());
            if(v.x <= (projectiles[j].GetSize().x+enemies[i].GetSize().x)/2 && v.y <= (projectiles[j].GetSize().y+enemies[i].GetSize().y)/2)
            {
                enemies[i].setHp(enemies[i].getHp()-projectiles[j].getDmg());
                //std::cout << enemies[i].getHp() << std::endl;
                generateBloodParticle(projectiles[j].GetPosition(),projectiles[j].GetRotation(), Storage::getInstance().getParticleType(0));
                projectiles[j].setDead();
                enemies[i].playSound();
                if(enemies[i].getHp() <= 0)
                {
                    enemies[i].playSound();
                    enemies[i].setDead();
                    generateDecal(enemies[i], Storage::getInstance().getDecalType(enemies[i].getDecal()));
                }
            }
        }
    }
    for(unsigned int i = 0; i < powerups.size(); ++i)
    {
        sf::Vector2f v = Utility::calcDistanceV(powerups[i].GetPosition(),player.GetPosition());
        if (v.x <= (player.GetSize().x+powerups[i].GetSize().x)/2 && v.y <= (player.GetSize().y+powerups[i].GetSize().y)/2)
        {
            player.setHp(player.getHp() + powerups[i].getHeal());
            player.setPowerUp(powerups[i]);
            powerups[i].setDead();
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
    powerups.erase(std::remove_if(powerups.begin(),powerups.end(),stillObject::isDead),powerups.end());
}

void Game::generateBloodParticle(sf::Vector2f pos, float rot, ParticleType pt)
{
    float random = Storage::getInstance().getRandom(10, 20);
    for (int i = 0; i < random; ++i)
    {
        Particle tmp_particle = Particle(pt, pos, rot+Storage::getInstance().getRandom(-20, 20), Storage::getInstance().getRandom(2, 4));
        particles.push_back(tmp_particle);
    }

}

void Game::generateShellParticle(sf::Vector2f pos, float rot, ParticleType pt)
{
    Particle tmp_particle = Particle(pt, pos, rot+90, Storage::getInstance().getRandom(2, 4));
    particles.push_back(tmp_particle);
}


void Game::generateDecal(Enemy& enemy, DecalType dt)
{
    Decal tmp_decal = Decal(dt, enemy.GetPosition(), enemy.GetRotation());
    tmp_decal.SetScale(enemy.GetScale());
    decals.push_back(tmp_decal);
}
