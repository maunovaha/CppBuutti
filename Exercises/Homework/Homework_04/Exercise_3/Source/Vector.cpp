#include "Vector.h"
#include <iostream>

Vector::Vector(int origin_x, int origin_y, int direction_x, int direction_y)
    : origin_x{origin_x}, origin_y{origin_y}, direction_x{direction_x}, direction_y{direction_y}
{
}

void Vector::print() const
{
    std::cout << "Vector, origin {" << origin_x << ", " << origin_y << "}, " 
              << "direction {" << direction_x << ", " << direction_y << "}" << std::endl;
}
