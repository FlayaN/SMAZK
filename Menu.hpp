#include "SFML/Graphics.hpp"
#include "Gui.hpp"

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
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::String text;
    sf::Sprite crosshair, bg;
    sf::Image crosshairImg, bgImg;
    sf::Event event;
    std::vector<Gui> guis;
    //Gui mainscreen, highscore, options, exit, back;
    sf::Image newgameImg, highscoreImg, optionsImg, aboutImg, exitImg, backImg;
    int currMenu;
};
#endif
