#include "Vector.h"
#include <iostream>

int main()
{
    Vector v1{{-1, -1}, {3, 4}};
    v1.print();

    Point v1_end_point = v1.end_point();

    std::cout << "The vector end point is: {" << v1_end_point.x << ", " 
              << v1_end_point.y << "}" << std::endl;

    return 0;
}