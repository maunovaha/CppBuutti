#include "Geometry/Vector.h"
#include <iostream>
#include <limits>

void clear_failed_stream_state()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

geometry::Vector read_vector()
{
    int origin_x = 0;
    int origin_y = 0;
    int direction_x = 0;
    int direction_y = 0;

    if (!(std::cin >> origin_x >> origin_y >> direction_x >> direction_y)) {
        std::cout << "Invalid data! Try again." << std::endl;
        
        // In case of cin error, we need to clear the failed state of stream, as well as
        // discard unprocessed characters. Otherwise, we will get an infinite loop when 
        // user enters invalid data.
        clear_failed_stream_state();

        return read_vector();
    }

    return {{origin_x, origin_y}, {direction_x, direction_y}};
}

int main()
{
    std::cout << "Give the first vector origin and direction as e.g. `0 0 0 5`: " << std::endl;
    geometry::Vector v1 = read_vector();

    std::cout << "Give the second vector origin and direction as e.g. `0 0 5 0`: " << std::endl;
    geometry::Vector v2 = read_vector();

    if (geometry::Vector::is_perpendicular(v1, v2)) {
        std::cout << "\nVectors are perpendicular!" << std::endl;
    }
    else {
        std::cout << "\nVectors are not perpendicular!" << std::endl;
    }

    return 0;
}