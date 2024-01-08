#include <SFML/System/Vector2.hpp>
#include <math.h>

template <typename T>
T Vector2length(const sf::Vector2<T> &v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}
