#include "SFML/Graphics.hpp"
#include "GuiButton.hpp"

#include <vector>
#include <iostream>

#ifndef GUIqqq
#define GUIqqq
class Gui
{
public:
    Gui(){}
    void addButton(sf::Image& image, sf::Vector2f pos, int targetMenu);
    void addSwitchButton(sf::Image& image, sf::Vector2f pos, int function);
    void addText(std::string text, sf::Font& font, sf::Vector2f pos);
    void addImage(sf::Image& image, sf::Vector2f pos);

    void clearGui();

    std::vector<GuiButton>& getButtons();
    std::vector<GuiButton>& getSwitchButtons();
    std::vector<sf::Sprite>& getImages();
    std::vector<sf::String>& getTexts();

private:
    std::vector<GuiButton> buttons;
    std::vector<GuiButton> switchButtons;
    std::vector<sf::String> texts;
    std::vector<sf::Sprite> images;
};
#endif
