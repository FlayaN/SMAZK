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
    onoffImg.LoadFromFile("resources\\images\\OnOffSwitch.png");
    font.LoadFromFile("resources\\menutext.ttf");

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
    guis.push_back(reloadHighScore(highscore));

    Gui options;
    menutext = "Options";
    options.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-70, 50));
    options.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, SCREEN_SIZE_HEIGHT-50), 0);

    menutext = "Sound";
    options.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-70, 150));
    options.addSwitchButton(onoffImg, sf::Vector2f((SCREEN_SIZE_WIDTH/2-20), 230), 1);

    menutext = "High Graphics";
    options.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-110, 250));
    options.addSwitchButton(onoffImg, sf::Vector2f((SCREEN_SIZE_WIDTH/2-20), 330), 2);

    menutext = "Improve Framerate";
    options.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-150, 350));
    options.addSwitchButton(onoffImg, sf::Vector2f((SCREEN_SIZE_WIDTH/2-20), 430), 4);

    guis.push_back(options);

    Gui about;
    menutext = "About";
    about.addText(menutext, font, sf::Vector2f((SCREEN_SIZE_WIDTH/2)-70, 50));
    about.addButton(backImg, sf::Vector2f(SCREEN_SIZE_WIDTH/2, SCREEN_SIZE_HEIGHT-50), 0);
    menutext =  "SMAZK is a game developed in C++ by\nthe swedish students Hannes Feldt,\nYngve Wahlin and Anders Wikstr�m.";
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
            std::vector<GuiButton>& switchButton = guis[currMenu].getSwitchButtons();
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
                    else if(buttons[i].targetMenu == 1)
                    {
                        currMenu = buttons[i].targetMenu;
                        reloadHighScore(guis[1]);
                    }
                    else
                    {
                        currMenu = buttons[i].targetMenu;
                    }
                }
            }
            for (unsigned int i = 0; i < switchButton.size(); ++i)
            {
                if(Utility::contains(switchButton[i],event.MouseButton.X, event.MouseButton.Y))
                {
                    if(switchButton[i].targetMenu == 0)
                    {
                        switchButton[i].targetMenu = 1;
                        Storage::getInstance().setSound(true);
                        switchButton[i].SetSubRect(sf::IntRect(0, 40, 60, 80));
                    }
                    else if(switchButton[i].targetMenu == 1)
                    {
                        switchButton[i].targetMenu = 0;
                        Storage::getInstance().setSound(false);
                        switchButton[i].SetSubRect(sf::IntRect(0, 0, 60, 40));
                    }
                    else if(switchButton[i].targetMenu == 2)
                    {
                        switchButton[i].targetMenu = 3;
                        Storage::getInstance().setGraphicsHigh(false);
                        switchButton[i].SetSubRect(sf::IntRect(0, 0, 60, 40));
                    }
                    else if(switchButton[i].targetMenu == 3)
                    {
                        switchButton[i].targetMenu = 2;
                        Storage::getInstance().setGraphicsHigh(true);
                        switchButton[i].SetSubRect(sf::IntRect(0, 40, 60, 80));
                    }
                    else if(switchButton[i].targetMenu == 4)
                    {
                        switchButton[i].targetMenu = 5;
                        Storage::getInstance().setImproveFramerate(false);
                        switchButton[i].SetSubRect(sf::IntRect(0, 0, 60, 40));
                    }
                    else if(switchButton[i].targetMenu == 5)
                    {
                        switchButton[i].targetMenu = 4;
                        Storage::getInstance().setImproveFramerate(true);
                        switchButton[i].SetSubRect(sf::IntRect(0, 40, 60, 80));
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
    for (unsigned int i = 0; i < guis[currMenu].getSwitchButtons().size(); ++i)
    {
        window.Draw(guis[currMenu].getSwitchButtons()[i]);
    }

    window.Draw(crosshair);

    window.Display();
}

Gui& Menu::reloadHighScore(Gui& highscore)
{
    highscore.clearGui();
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
    return highscore;
}

