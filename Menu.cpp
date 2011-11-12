#include "Menu.hpp"
#include "Utility.hpp"

Menu::Menu(sf::RenderWindow& window)
    : window(window)
{
    currMenu=0;
    crosshairImg.LoadFromFile("resources\\images\\crosshair.png");
    bgImg.LoadFromFile("resources\\images\\floor.png");
    newgameImg.LoadFromFile("resources\\images\\StartGame.png");
    highscoreImg.LoadFromFile("resources\\images\\HighScore.png");
    optionsImg.LoadFromFile("resources\\images\\Options.png");
    aboutImg.LoadFromFile("resources\\images\\About.png");
    exitImg.LoadFromFile("resources\\images\\Exit.png");
    backImg.LoadFromFile("resources\\images\\Back.png");
    font.LoadFromFile("resources\\menutext.ttf");

    Storage::getInstance().setHighScoreType(config.getHighScores());

    bg.SetImage(bgImg);

    crosshair.SetImage(crosshairImg);
    crosshair.SetCenter(crosshairImg.GetWidth()/2,crosshairImg.GetHeight()/2);

    Gui mainscreen;
    menutext = "SuperMegaAwesomeZombieKiller";
    mainscreen.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-250, 50));
    mainscreen.addButton(newgameImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 150), -1);
    mainscreen.addButton(highscoreImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 200), 1);
    mainscreen.addButton(optionsImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 250), 2);
    mainscreen.addButton(aboutImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 300), 3);
    mainscreen.addButton(exitImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, 350), 4);
    guis.push_back(mainscreen);

    Gui highscore;
    menutext = "HighScore";
    highscore.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-100, 50));

    menutext = "First:";
    highscore.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-120, 150));

    menutext = Utility::int2Str(config.getInt("point", 1, "Highscore1", "resources\\ini\\highscores.ini"));
    highscore.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2), 150));

    menutext = "Second:";
    highscore.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-120, 200));

    menutext = Utility::int2Str(config.getInt("point", 1, "Highscore2", "resources\\ini\\highscores.ini"));
    highscore.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2), 200));

    menutext = "Third:";
    highscore.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-120, 250));

    menutext = Utility::int2Str(config.getInt("point", 1, "Highscore3", "resources\\ini\\highscores.ini"));
    highscore.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2), 250));

    highscore.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, SCREEN_SIZE_HEIGHT-50), 0);
    guis.push_back(highscore);

    Gui options;
    menutext = "Options";
    options.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-70, 50));
    options.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, SCREEN_SIZE_HEIGHT-50), 0);
    guis.push_back(options);

    Gui about;
    menutext = "About";
    about.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-70, 50));
    about.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, SCREEN_SIZE_HEIGHT-50), 0);
    menutext =  "SMAZK is a game developed in C++ by\nthe swedish students Hannes Feldt,\nYngve Wahlin and Anders Wikström.";
    about.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-270, 250));
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

    for (unsigned int i = 0; i < guis[currMenu].getTexts().size(); ++i)
    {
        window.Draw(guis[currMenu].getTexts()[i]);
    }

    window.Draw(crosshair);

    window.Display();
}

