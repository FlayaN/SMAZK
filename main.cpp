#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.cpp"
#include <cstdlib>
#include <ctime>

//Defines constants
#define SCREEN_SIZE_WIDTH   1280
#define SCREEN_SIZE_HEIGHT  720
#define SCREEN_BIT_SIZE     32

int main()
{
    // Create the main rendering window
    sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, SCREEN_BIT_SIZE), "Super Mega Awesome Zombie Killer");
    window.SetFramerateLimit(60);
    window.UseVerticalSync(true);
    Game game(window);
    game.run();

    return EXIT_SUCCESS;
}

