#include "SFML/Graphics.hpp"
#include "Gui.hpp"
#include "Storage.hpp"
#include "Config.hpp"
#include "Utility.hpp"

#include <iostream>
#include <vector>

#ifndef MENUqqq
#define MENUqqq

#define SCREEN_SIZE_WIDTH   1280
#define SCREEN_SIZE_HEIGHT  720

class Menu
{
public:
    Menu(sf::RenderWindow& window);

    bool run();
    void draw();
    Gui& reloadHighScore(Gui& highscore);
private:
    sf::RenderWindow& window;
    sf::String text;
    sf::Sprite crosshair, bg;
    sf::Image crosshairImg, bgImg;
    sf::Event event;
    std::vector<Gui> guis;
    std::string menutext;
    Config config;
    sf::Image newgameImg, highscoreImg, optionsImg, aboutImg, exitImg, backImg, onoffImg;
    int currMenu;
    sf::Font font;
};
#endif
