#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
//Defines constants
#define SCREEN_SIZE_WIDTH   800
#define SCREEN_SIZE_HEIGHT  600
#define SCREEN_BIT_SIZE     32

int main()
{
    // Create the main rendering window
    sf::RenderWindow game(sf::VideoMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT, SCREEN_BIT_SIZE), "Super Mega Awesome Zombie Slayer");

    //Using clock to limit framerate
    sf::Clock clock;

    //Creates a iamge
    sf::Image player;

    // Set size of the shape box
    if (!player.LoadFromFile("player.png"))
    {
        return EXIT_FAILURE;
    }

    // Start game loop
    while (game.IsOpened())
    {
        // Process events
        sf::Event event;
        while (game.GetEvent(event))
        {
            // Close window : exit
            if (event.Type == sf::Event::Closed)
            {
                game.Close();
            }

        }

        // If the player presses W or Up arrow key
        if(game.GetInput().IsKeyDown(sf::Key::W) || game.GetInput().IsKeyDown(sf::Key::Up))
        {

        }

        // If the player presses A or Left arrow key
        if(game.GetInput().IsKeyDown(sf::Key::A) || game.GetInput().IsKeyDown(sf::Key::Left))
        {

        }

        // If the player presses S or Down arrow key
        if(game.GetInput().IsKeyDown(sf::Key::S) || game.GetInput().IsKeyDown(sf::Key::Down))
        {

        }

        // If the player presses D or Right arrow key
        if(game.GetInput().IsKeyDown(sf::Key::D) || game.GetInput().IsKeyDown(sf::Key::Right))
        {

        }

        // Get elepsed time since last loop
        float time = clock.GetElapsedTime();
        clock.Reset();

        // Clear the screen (fill it with black color)
        game.Clear();

        // Display window contents on screen
        game.Display();
    }

    return EXIT_SUCCESS;
}
