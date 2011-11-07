#include "SFML/Graphics.hpp"

#include <string>
#include <cmath>
#include <sstream>

#ifndef UTILITYqqq
#define UTILITYqqq

namespace Utility
{
    float calcAngle(sf::Vector2f p1, sf::Vector2f p2);
    float calcDistance(sf::Vector2f p1, sf::Vector2f p2);
    sf::Vector2f calcDistanceV(sf::Vector2f p1, sf::Vector2f p2);
    std::string int2Str(int x);
}
#endif
