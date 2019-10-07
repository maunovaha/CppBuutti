#include "Person.h"

int main()
{   
    Person p1{"John Jackson", "Male", "Artist", {1, 1, 1987}, {11, 12, 2000}};
    p1.introduce_yourself();

    Person p2{"Mickey Mouse", "Male", "Detective", {3, 4, 1977}, {7, 2, 2011}, true};
    p2.introduce_yourself();

    Person p3{"Emma Kidman", "Female", "Singer", {1, 1, 1960}, {6, 5, 1978}, true};
    p3.introduce_yourself();

    return 0;
}