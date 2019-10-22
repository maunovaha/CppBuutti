#include "Application.h"
#include "InputReader.h"
#include "Person.h"
#include <iostream>

Application::Application()
{
    run();
}

void Application::run()
{
    std::cout << "What is the first name?" << std::endl;
    std::string first_name = InputReader::read_str();

    std::cout << "And last name?" << std::endl;
    std::string last_name = InputReader::read_str();

    std::cout << "And age?" << std::endl;
    int age{};

    if (!(InputReader::read_int(age, Person::min_age, Person::max_age))) {
        std::cerr << "That is not a valid age!" << std::endl;
        return run();
    }

    Person person{first_name, last_name, age};
}
