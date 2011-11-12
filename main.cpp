#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include "Menu.hpp"

#include <cstdlib>
#include <ctime>

//Defines constants
#define SCREEN_SIZE_WIDTH   1280
#define SCREEN_SIZE_HEIGHT  720
#define SCREEN_BIT_SIZE     32

int main()
{
    sf::Event event;
    bool menurun = true;
    bool gamerun = true;

    // Create the main rendering window
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, SCREEN_BIT_SIZE), "Super Mega Awesome Zombie Killer");
    window.SetFramerateLimit(60);
    window.UseVerticalSync(true);
    window.ShowMouseCursor(false);

    Menu menu(window);
    Game game(window);

    while (window.IsOpened())
    {
        if(menurun==true)
        {
            menurun = menu.run();
        }
        else
        {
            if(gamerun == true)
            {
                gamerun = !game.run();

            }
            else
            {
                menurun = true;
            }
        }
    }
    return EXIT_SUCCESS;
}

