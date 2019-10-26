#include "Vector2.h"

Vector2::Vector2(const float x, const float y) : x_{x}, y_{y}
{
}

std::ostream& operator <<(std::ostream& os, const Vector2& other)
{
    os << "(" << other.x_ << ", " << other.y_ << ")";
    return os;
}

Vector2 operator *(const float scalar, const Vector2& other)
{
    return other * scalar;
}
