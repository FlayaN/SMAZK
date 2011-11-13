#include "Gui.hpp"

void Gui::addButton(sf::Image& image, sf::Vector2f pos, int targetMenu)
{
    GuiButton tmp_button;
    tmp_button.targetMenu = targetMenu;
    tmp_button.SetImage(image);
    tmp_button.SetSubRect(sf::IntRect(0, 0, image.GetWidth(), image.GetHeight()/2));
    tmp_button.SetCenter(image.GetWidth()/2,image.GetHeight()/4);
    tmp_button.SetPosition(pos);
    buttons.push_back(tmp_button);
}

void Gui::addSwitchButton(sf::Image& image, sf::Vector2f pos, int function)
{
    GuiButton tmp_button;
    tmp_button.targetMenu = function;
    tmp_button.SetImage(image);
    tmp_button.SetSubRect(sf::IntRect(0, image.GetHeight()/2, image.GetWidth(), image.GetHeight()));
    tmp_button.SetCenter(image.GetWidth()/2,image.GetHeight()/4);
    tmp_button.SetPosition(pos);
    switchButtons.push_back(tmp_button);
}

void Gui::addText(std::string text, sf::Font& font, sf::Vector2f pos)
{
    sf::String tmp_text;
    tmp_text.SetFont(font);
    tmp_text.SetSize(50);
    tmp_text.SetColor(sf::Color(255, 255, 255, 255));
    tmp_text.SetText(text);
    tmp_text.SetPosition(pos);

    texts.push_back(tmp_text);
}

void Gui::addImage(sf::Image& image, sf::Vector2f pos)
{
    sf::Sprite tmp_sprite;
    tmp_sprite.SetImage(image);
    tmp_sprite.SetCenter(image.GetWidth()/2,image.GetHeight()/2);
    tmp_sprite.SetPosition(pos);
    images.push_back(tmp_sprite);
}

void Gui::clearGui()
{
    buttons.clear();
    images.clear();
    texts.clear();
}

std::vector<GuiButton>& Gui::getButtons()
{
    return buttons;
}

std::vector<GuiButton>& Gui::getSwitchButtons()
{
    return switchButtons;
}

std::vector<sf::Sprite>& Gui::getImages()
{
    return images;
}

std::vector<sf::String>& Gui::getTexts()
{
    return texts;
}
