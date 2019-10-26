#include "Vector2.h"
#include <iostream>

int main()
{
    const Vector2 v1{1.0f, 2.0f};
    const Vector2 v2{1.0f, 2.0f};

    std::cout << v1 << " + " << v2 << " = " << (v1 + v2) << "\n"
              << v1 << " - " << v2 << " = " << (v1 - v2) << "\n"
              << v1 << " * 2" << " = " << (v1 * 2.0f) << "\n"
              << v1 << " / 2" << " = " << (v1 / 2.0f) << "\n"
              << "2 * " << v1 << " = " << (2.0f * v1) << "\n";

    return 0;
}