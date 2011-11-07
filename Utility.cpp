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
