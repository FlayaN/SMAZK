#include "Utility.hpp"

float Utility::calcAngle(sf::Vector2f p1, sf::Vector2f p2)//float x1, float y1, float x2,float y2)
{
    return std::atan2((p2.x-p1.x),(p1.y-p2.y));
}

float Utility::calcDistance(sf::Vector2f p1,sf::Vector2f p2)
{
    return std::sqrt(std::pow((p1.x-p2.x),2)+std::pow(p1.y-p2.y,2));
}

sf::Vector2f Utility::calcDistanceV(sf::Vector2f p1,sf::Vector2f p2)
{
    return sf::Vector2f(std::abs(p1.x-p2.x),std::abs(p1.y-p2.y));
}

std::string Utility::int2Str(int x)
{
  std::stringstream ss;
  ss << x;
  return ss.str();
}

bool Utility::contains(sf::Sprite sp, int x, int y){

    float posX1 = sp.GetPosition().x - sp.GetSize().x/2;
    float posY1 = sp.GetPosition().y - sp.GetSize().y/2;
    //sf::Vector2f center = sp.GetCenter();
    float posX2 = sp.GetPosition().x + sp.GetSize().x/2;
    float posY2 = sp.GetPosition().y + sp.GetSize().y/2;
    //sf::Vector2f
    //if(s
    if(x > posX1 && x < posX2 && y > posY1 && y < posY2)
         return true;

    return false;

}
