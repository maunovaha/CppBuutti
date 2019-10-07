#include "Person.h"
#include <iostream>

int main()
{   
    Person p1{"John Jackson", "Male", "Artist", {1, 1, 1987}, {11, 12, 2000}};
    Person p2{"Mickey Mouse", "Male", "Detective", {3, 4, 1977}, {7, 2, 2011}, true};
    Person p3{"Emma Kidman", "Female", "Singer", {1, 1, 1960}, {6, 5, 1978}, true};

    p1.debug();
    p2.debug();
    p3.debug();
    Person::debug(); // The method `debug()` is static, so we can call it without instance as well.

    // This works because by default variables and functions are public when using struct.
    std::cout << "Current Person::id value is: " << Person::id << std::endl;

    return 0;
}