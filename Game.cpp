#include "Game.hpp"


#define PI 3.14159265
#define sqrt2 1.41421356
#define sqrt2inv 0.707106781
#define SCREEN_SIZE_WIDTH 1280
#define SCREEN_SIZE_HEIGHT 720

Game::Game(sf::RenderWindow& window)
    : window(window)
{
    playerImg.LoadFromFile("resources\\images\\player.png");
    crosshairImg.LoadFromFile("resources\\images\\crosshair.png");
    bgImg.LoadFromFile("resources\\images\\floor.png");
    hpHudImg.LoadFromFile("resources\\images\\hpHud.png");
    weaponHudImg.LoadFromFile("resources\\images\\weaponHud.png");
    font.LoadFromFile("resources\\zombie.ttf");

    gameTime=0;
    frameHelp=0;
    currWave=-1;
    gameScore=0;
    finished = false;
    victory = false;
    initStorage();
}

Game::~Game()
{
    Storage::getInstance().resetStorage();
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

    player = Player(180.0f, 100,Weapon(storage.getWeaponType(0), sf::Vector2f(player.GetPosition()), 0));
    player.SetImage(playerImg);
    player.SetPosition(500.0f,300.0f);
    player.SetCenter(playerImg.GetWidth()/2,playerImg.GetHeight()/2);

    bg.SetImage(bgImg);

    crosshair.SetImage(crosshairImg);
    crosshair.SetCenter(crosshairImg.GetWidth()/2,crosshairImg.GetHeight()/2);

    hpHud.SetImage(hpHudImg);
    hpHud.SetPosition(85,SCREEN_SIZE_HEIGHT-90);

    weaponHud.SetImage(weaponHudImg);
    weaponHud.SetCenter(weaponHudImg.GetWidth()/2, weaponHudImg.GetHeight()/2);
    weaponHud.SetPosition(SCREEN_SIZE_WIDTH-80,SCREEN_SIZE_HEIGHT-50);

    waveText.SetFont(font);
    waveText.SetSize(50);
    waveText.SetColor(sf::Color(255, 0, 0, 255));

    scoreText.SetFont(font);
    scoreText.SetSize(50);
    scoreText.SetColor(sf::Color(255, 0, 0, 255));
    scoreText.SetPosition(SCREEN_SIZE_WIDTH/2-115, 5);

    enemysText.SetFont(font);
    enemysText.SetSize(30);
    enemysText.SetColor(sf::Color(0, 0, 0, 255));
    enemysText.SetPosition(SCREEN_SIZE_WIDTH/2-100, 50);

    fpsText.SetFont(font);
    fpsText.SetSize(50);
    fpsText.SetColor(sf::Color(255, 0, 0, 255));
    fpsText.SetPosition(SCREEN_SIZE_WIDTH - 170, 5);

    ammoText.SetFont(font);
    ammoText.SetSize(50);
    ammoText.SetColor(sf::Color(0, 0, 255, 255));
    ammoText.SetPosition(SCREEN_SIZE_WIDTH - 400,SCREEN_SIZE_HEIGHT - 80);

    victoryText.SetFont(font);
    victoryText.SetSize(200);
    victoryText.SetColor(sf::Color(0, 0, 255, 255));
    victoryText.SetText("    Victory\nPress RETURN \nto continue");

    playerHp = sf::Shape::Rectangle(100, SCREEN_SIZE_HEIGHT - 80, 400, SCREEN_SIZE_HEIGHT - 40, sf::Color(0, 255, 0, 255));
    hpBg = sf::Shape::Rectangle(100, SCREEN_SIZE_HEIGHT - 80, 400, SCREEN_SIZE_HEIGHT - 40, sf::Color(255, 0, 0, 255));
}

bool Game::run()
{
    while (window.GetEvent(event)) //Have to exist to update inputs
    {
        if (event.Type == sf::Event::Closed)
        {
            window.Close();
        }
        if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Return) && victory)
        {
            highScore(gameScore);
        }
    }
    crosshair.SetPosition(window.GetInput().GetMouseX(),window.GetInput().GetMouseY());
    draw();
    if(!victory)
        updateGameState();
    return finished;
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
    for (unsigned int i = 0; i < particles.size(); ++i)
    {
        window.Draw(particles[i]);
    }
    for (unsigned int i = 0; i < powerups.size(); ++i)
    {
        window.Draw(powerups[i]);
    }
    for (unsigned int i = 0; i < weapons.size(); ++i)
    {
        window.Draw(weapons[i]);
    }
    for (unsigned int i = 0; i < enemies.size(); ++i)
    {
        window.Draw(enemies[i]);
    }
    for (unsigned int i = 0; i < projectiles.size(); ++i)
    {
        window.Draw(projectiles[i]);
    }

    window.Draw(player);
    window.Draw(crosshair);
    window.Draw(ammoText);
    window.Draw(scoreText);
    window.Draw(fpsText);
    window.Draw(waveText);
    window.Draw(enemysText);
    window.Draw(hpBg);
    window.Draw(playerHp);
    window.Draw(hpHud);
    window.Draw(weaponHud);
    window.Draw(player.getWeapon());
    if(victory)
        window.Draw(victoryText);

    window.Display();
}

void Game::updateGameState()
{
    elapsedTime=clock.GetElapsedTime();
    gameTime += elapsedTime;
    frameTime = 1.0f / elapsedTime;

    clock.Reset();

    playerHp.SetPointPosition(1, (player.getHp()*3)+100, playerHp.GetPointPosition(1).y);
    playerHp.SetPointPosition(2, (player.getHp()*3)+100, playerHp.GetPointPosition(2).y);

    if(gameTime > frameHelp)
    {
        ++frameHelp;
        fpsText.SetText("FPS " + Utility::int2Str(frameTime));
    }

    int currAmmo = player.getWeapon().getAmmo();
    if(currAmmo < 0)
    {
        ammoText.SetText("Ammo inf.");
    }
    else
    {
        ammoText.SetText("Ammo " + Utility::int2Str(currAmmo));
    }

    waveText.SetText("Wave " + Utility::int2Str(currWave+1));
    enemysText.SetText("Enemys " + Utility::int2Str(enemies.size()));
    scoreText.SetText("Score " + Utility::int2Str(gameScore));


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
        if(Storage::getInstance().isImproveFramerate())
        {
            improveFramerate();
        }
        WaveType tmp_wave = Storage::getInstance().getWaveType(currWave);
        //int enemyTypesPerWave = tmp_wave.total/tmp_wave.types;
        for (int i = 0; i < tmp_wave.types; ++i)
        {
            for(int j = 0; j < tmp_wave.countOfEnemy[i]; ++j)
            {
                sf::Vector2f pos;

                int randInt = Storage::getInstance().getRandom(0, 3);
                switch(randInt)
                {
                case 0:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(-30*tmp_wave.countOfEnemy[i], 0), Storage::getInstance().getRandom(0, SCREEN_SIZE_HEIGHT));
                    break;
                case 1:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(SCREEN_SIZE_WIDTH, SCREEN_SIZE_WIDTH+30*tmp_wave.countOfEnemy[i]), Storage::getInstance().getRandom(0, SCREEN_SIZE_HEIGHT));
                    break;
                case 2:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(0, SCREEN_SIZE_WIDTH), Storage::getInstance().getRandom(-30*tmp_wave.countOfEnemy[i],0));
                    break;
                default:
                    pos = sf::Vector2f(Storage::getInstance().getRandom(0, SCREEN_SIZE_WIDTH),Storage::getInstance().getRandom(SCREEN_SIZE_HEIGHT,SCREEN_SIZE_HEIGHT+30*tmp_wave.countOfEnemy[i]));
                    break;
                }
                enemies.push_back(Enemy(Storage::getInstance().getEnemyType(tmp_wave.typeOfEnemy[i]), pos));
            }
        }
        int random = Storage::getInstance().getRandom(1, 1+currWave/3);
        for(unsigned int i = 0; i < random; ++i)
        {
            int randInt = Storage::getInstance().getRandom(0, config.getInt("number", 1, "init", "resources\\ini\\powerups.ini") - 1);
            powerups.push_back(PowerUp(Storage::getInstance().getPowerUpType(randInt), sf::Vector2f(Storage::getInstance().getRandom(0, SCREEN_SIZE_WIDTH), Storage::getInstance().getRandom(0, SCREEN_SIZE_HEIGHT)), 0));
        }

        random = Storage::getInstance().getRandom(1, 1+currWave/2);
        for(unsigned int i = 0; i < random; ++i)
        {
            int randInt = Storage::getInstance().getRandom(1, config.getInt("number", 1, "init", "resources\\ini\\weapons.ini") - 1);
            weapons.push_back(Weapon(Storage::getInstance().getWeaponType(randInt), sf::Vector2f(Storage::getInstance().getRandom(0, SCREEN_SIZE_WIDTH), Storage::getInstance().getRandom(0, SCREEN_SIZE_HEIGHT)), 0));
        }
    }
    else if(currWave+1 == waves && enemies.size() == 0)
    {
        victory = true;
    }
}

void Game::moveEntities()
{
    //Moves Enemies
    for (unsigned int i = 0; i < enemies.size(); ++i)
    {
        float speed = enemies[i].getSpeed();
        float rotation = (Utility::calcAngle(player.GetPosition(),enemies[i].GetPosition()))+PI/2;
        float dx = elapsedTime*speed*std::cos(rotation);
        float dy = elapsedTime*speed*std::sin(rotation);
        enemies[i].SetRotation((-rotation*180/PI)-90);
        enemies[i].Move(dx,dy);
    }
    //Moves Projectiles
    for (unsigned int i = 0; i < projectiles.size(); ++i)
    {
        float speed = projectiles[i].getSpeed();//*0.1;
        float rotation = -(projectiles[i].GetRotation()/180*PI)+PI/2;
        float dx = elapsedTime*speed*std::cos(rotation);
        float dy = elapsedTime*speed*std::sin(rotation);
        //projectiles[i].SetRotation((-rotation*180/PI)-90);
        projectiles[i].Move(dx,dy);
    }
    for (unsigned int i = 0; i < particles.size(); ++i)
    {
        float speed = particles[i].getSpeed();//*0.1;
        float rotation = -(particles[i].GetRotation()/180*PI)+PI/2;
        float dx = elapsedTime*speed*std::cos(rotation);
        float dy = elapsedTime*speed*std::sin(rotation);
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
    if(dx != 0 && dy != 0)
    {
        dx *= sqrt2inv;
        dy *= sqrt2inv;
    }

    // Rotate the player to the crosshair
    player.Move(dx*player.getSpeed()*elapsedTime,dy*player.getSpeed()*elapsedTime);;
    //sf::Vector2f mouse(window.GetInput().GetMouseX(),window.GetInput().GetMouseY());
    float rotation = (Utility::calcAngle(player.GetPosition(),sf::Vector2f(window.GetInput().GetMouseX(),window.GetInput().GetMouseY())))+PI/2;
    player.SetRotation((-rotation*180/PI)-90);

}

void Game::attack()
{
    if(window.GetInput().IsMouseButtonDown(sf::Mouse::Left) && player.getWeapon().isAttackReady())
    {
        player.attack();
        Projectile tmp_projectile = Projectile(Storage::getInstance().getProjectileType(player.getWeapon().getProjectile()), sf::Vector2f(player.GetPosition()), player.GetRotation());
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

            player.setHp(player.getHp()-enemies[i].getDmg());
            gameScore -= enemies[i].getDmg();
        }
        for(unsigned int j = 0; j < projectiles.size(); ++j)
        {
            v = Utility::calcDistanceV(enemies[i].GetPosition(),projectiles[j].GetPosition());
            if(v.x <= (projectiles[j].GetSize().x+enemies[i].GetSize().x)/2 && v.y <= (projectiles[j].GetSize().y+enemies[i].GetSize().y)/2)
            {
                generateBloodParticle(projectiles[j].GetPosition(),projectiles[j].GetRotation(), Storage::getInstance().getParticleType(0));
                if(projectiles[j].isPiercing())
                {
                    enemies[i].setHp(enemies[i].getHp()-(projectiles[j].getDmg()*60)*elapsedTime);
                }
                else
                {
                    enemies[i].setHp(enemies[i].getHp()-projectiles[j].getDmg());
                    projectiles[j].setDead();
                }
                enemies[i].playSound();
                if(enemies[i].getHp() <= 0)
                {
                    enemies[i].playSound();
                    enemies[i].setDead();
                    gameScore += Storage::getInstance().getEnemyType(enemies[i].getName()).maxHp;
                    generateDecal(enemies[i], Storage::getInstance().getDecalType(enemies[i].getDecal()));
                }
            }
        }
    }
    if ( player.getHp() <= 0)
    {
        highScore(gameScore);
    }
    for(unsigned int i = 0; i < powerups.size(); ++i)
    {
        sf::Vector2f v = Utility::calcDistanceV(powerups[i].GetPosition(),player.GetPosition());
        if (v.x <= (player.GetSize().x+powerups[i].GetSize().x)/2 && v.y <= (player.GetSize().y+powerups[i].GetSize().y)/2)
        {
            if(powerups[i].isInstant())
            {
                player.setHp(player.getHp() + powerups[i].getHeal());
            }
            else
            {
                player.setPowerUp(powerups[i]);
            }
            powerups[i].setDead();
        }
    }
    for(unsigned int i = 0; i < weapons.size(); ++i)
    {
        sf::Vector2f v = Utility::calcDistanceV(weapons[i].GetPosition(),player.GetPosition());
        if (v.x <= (player.GetSize().x+weapons[i].GetSize().x)/2 && v.y <= (player.GetSize().y+weapons[i].GetSize().y)/2)
        {
            player.setWeapon(weapons[i]);
            weapons[i].setDead();
        }
    }
    for(unsigned int i = 0; i < projectiles.size(); ++i)
    {
        if(projectiles[i].GetPosition().x <= 0 || projectiles[i].GetPosition().x >= SCREEN_SIZE_WIDTH || projectiles[i].GetPosition().y <= 0 || projectiles[i].GetPosition().y >= SCREEN_SIZE_HEIGHT)
        {
            projectiles[i].setDead();
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
    projectiles.erase(std::remove_if(projectiles.begin(),projectiles.end(),movingEntity::isDead),projectiles.end());
    enemies.erase(std::remove_if(enemies.begin(),enemies.end(),movingEntity::isDead),enemies.end());
    particles.erase(std::remove_if(particles.begin(),particles.end(),movingEntity::isDead),particles.end());
    powerups.erase(std::remove_if(powerups.begin(),powerups.end(),stillObject::isDead),powerups.end());
    weapons.erase(std::remove_if(weapons.begin(),weapons.end(),stillObject::isDead),weapons.end());
}

void Game::highScore(int score)
{
    int first = config.getInt("point", 1, "Highscore1", "resources\\ini\\highscores.ini");
    int second = config.getInt("point", 1, "Highscore2", "resources\\ini\\highscores.ini");
    int third = config.getInt("point", 1, "Highscore3", "resources\\ini\\highscores.ini");

    if(score >= first)
    {
        third = second;
        second = first;
        first = score;
    }
    else if(score < first && score >= second)
    {
        third = second;
        second = score;
    }
    else if(score < second && score >= third)
    {
        third = score;
    }
    else
    {
        std::cout << "No highscore for you mister" << std::endl;
    }
    config.setInt("point", first, "Highscore1", "resources\\ini\\highscores.ini");
    config.setInt("point", second, "Highscore2", "resources\\ini\\highscores.ini");
    config.setInt("point", third, "Highscore3", "resources\\ini\\highscores.ini");
    finished = true;
    gameTime=0;
}

void Game::generateBloodParticle(sf::Vector2f pos, float rot, ParticleType pt)
{
    float random = Storage::getInstance().getRandom(10, 30);
    for (int i = 0; i < random; ++i)
    {
        Particle tmp_particle = Particle(pt, pos, rot+Storage::getInstance().getRandom(-20, 20), Storage::getInstance().getRandom(120, 240));
        particles.push_back(tmp_particle);
    }
}

void Game::generateShellParticle(sf::Vector2f pos, float rot, ParticleType pt)
{
    Particle tmp_particle = Particle(pt, pos, rot+90, Storage::getInstance().getRandom(120, 240));
    particles.push_back(tmp_particle);
}


void Game::generateDecal(Enemy& enemy, DecalType dt)
{
    decals.push_back(Decal(dt, enemy.GetPosition(), enemy.GetRotation(), enemy.GetScale()));
    decals.rbegin()->playSound();
}

void Game::improveFramerate()
{
    window.Clear();
    window.Draw(bg);

    for (unsigned int i = 0; i < decals.size(); ++i)
    {
        window.Draw(decals[i]);
    }
    decals.clear();
    for (unsigned int i = 0; i < particles.size(); ++i)
    {
        window.Draw(particles[i]);
    }
    particles.clear();
    bgImg = window.Capture();
    bg.SetImage(bgImg);
}
