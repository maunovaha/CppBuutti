#include "Issue.h"
#include <iostream>

int main()
{
    const Issue issue1{"Fire!", "The building is on fire.", PriorityLevel::high};
    const Issue issue2{"Trash can", "It smells and should be changed.", PriorityLevel::medium};
    const Issue issue3{"Buy new curtains", "The old curtains are ugly.", PriorityLevel::low};

    std::cout << issue1 << "\n";
    std::cout << issue2 << "\n";
    std::cout << issue3 << "\n";

    return 0;
}