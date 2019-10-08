#include "Vector.h"
#include <iostream>

namespace geometry {

Vector::Vector(const Point& origin, const Point& direction) : origin{origin}, direction{direction}
{
}

bool Vector::is_perpendicular(const Vector& a, const Vector& b)
{
    return dot(a, b) == 0;
}

int Vector::dot(const Vector& a, const Vector& b)
{
    return (a.direction.x * b.direction.x) + (a.direction.y * b.direction.y);
}

Point Vector::end_point() const
{
    return {origin.x + direction.x, origin.y + direction.y}; 
}

void Vector::print() const
{
    std::cout << "Vector, origin {" << origin.x << ", " << origin.y << "}, " 
              << "direction {" << direction.x << ", " << direction.y << "}" << std::endl;
}

}