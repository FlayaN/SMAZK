#include "Menu.hpp"
#include "Utility.hpp"

Menu::Menu(sf::RenderWindow& window)
    : window(window)
{
    currMenu=0;
    crosshairImg.LoadFromFile("resources\\images\\crosshair.png");
    bgImg.LoadFromFile("resources\\images\\floor.png");
    font.LoadFromFile("resources\\zombie.ttf");
    newgameImg.LoadFromFile("resources\\images\\StartGame.png");
    highscoreImg.LoadFromFile("resources\\images\\HighScore.png");
    optionsImg.LoadFromFile("resources\\images\\Options.png");
    aboutImg.LoadFromFile("resources\\images\\About.png");
    exitImg.LoadFromFile("resources\\images\\Exit.png");
    backImg.LoadFromFile("resources\\images\\Back.png");

    bg.SetImage(bgImg);

    crosshair.SetImage(crosshairImg);
    crosshair.SetCenter(crosshairImg.GetWidth()/2,crosshairImg.GetHeight()/2);

    text.SetFont(font);
    text.SetSize(50);
    text.SetColor(sf::Color(255, 0, 0, 255));



    Gui mainscreen;
    mainscreen.addButton(newgameImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 150), -1);
    mainscreen.addButton(highscoreImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 200), 1);
    mainscreen.addButton(optionsImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 250), 2);
    mainscreen.addButton(aboutImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 300), 3);
    mainscreen.addButton(exitImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 350), 4);
    guis.push_back(mainscreen);

    Gui highscore;
    highscore.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 150), 0);
    guis.push_back(highscore);

    Gui options;
    options.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 150), 0);
    guis.push_back(options);

    Gui about;
    about.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 150), 0);
    guis.push_back(about);
}

bool Menu::run()
{

    while (window.GetEvent(event)) //Have to exist to update inputs
    {
        if (event.Type == sf::Event::Closed)
        {
            window.Close();
        }
        else if (event.Type == sf::Event::MouseMoved)
        {
            std::vector<GuiButton>& buttons = guis[currMenu].getButtons();
            for (unsigned int i = 0; i < buttons.size(); ++i)
            {

                if(Utility::contains(buttons[i],event.MouseMove.X, event.MouseMove.Y))
                {
                    buttons[i].SetSubRect(sf::IntRect(0, 40, 200, 80));
                }
                else
                {
                    buttons[i].SetSubRect(sf::IntRect(0, 0, 200, 40));
                }
            }
        }
        else if (event.Type == sf::Event::MouseButtonReleased)
        {
            std::vector<GuiButton>& buttons = guis[currMenu].getButtons();
            for (unsigned int i = 0; i < buttons.size(); ++i)
            {
                if(Utility::contains(buttons[i],event.MouseButton.X, event.MouseButton.Y))
                {
                    if(buttons[i].targetMenu == -1)
                    {
                        return 0;
                    }
                    else if(buttons[i].targetMenu == 4)
                    {
                        window.Close();
                    }
                    else
                    {
                        currMenu = buttons[i].targetMenu;
                    }
                }
            }
        }
    }
    draw();
    //std::cout << "en gång" << std::endl;
    crosshair.SetPosition(window.GetInput().GetMouseX(),window.GetInput().GetMouseY());
    return 1;
}

void Menu::draw()
{
    window.Clear();
    window.Draw(bg);
    for (unsigned int i = 0; i < guis[currMenu].getButtons().size(); ++i)
    {
        window.Draw(guis[currMenu].getButtons()[i]);
    }
    window.Draw(crosshair);
    window.Draw(text);

    window.Display();
}

