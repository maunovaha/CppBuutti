#include "Vector.h"
#include <iostream>

void perpendicular_check(const Vector& a, const Vector& b)
{
    if (Vector::is_perpendicular(a, b)) {
        std::cout << "Vectors are perpendicular!\n" << std::endl;
    }
    else {
        std::cout << "Vectors are not perpendicular!\n" << std::endl;
    }
}

int main()
{
    Vector v1{0, 0, 0, 5};
    Vector v2{0, 0, 5, 0};

    v1.print();
    v2.print();
    perpendicular_check(v1, v2);

    Vector v3{0, 0, 2, 5};
    Vector v4{0, 0, 10, -4};

    v3.print();
    v4.print();
    perpendicular_check(v3, v4);

    Vector v5{0, 0, 22, 65};
    Vector v6{0, 0, 60, 25};

    v5.print();
    v6.print();
    perpendicular_check(v5, v6);

    return 0;
}