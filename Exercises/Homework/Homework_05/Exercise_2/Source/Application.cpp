#include "Application.h"
#include "InputReader.h"
#include "UsernameGenerator.h"
#include <string>
#include <iostream>

Application::Application()
{
    run();
}

void Application::run() const
{
    for (;;) {
        std::cout << "What is your name?" << std::endl;
        const std::string name = InputReader::read_str();

        std::cout << "What is your birth year?" << std::endl;
        const int birth_year = InputReader::read_int();

        const std::string username = UsernameGenerator::generate(name, birth_year);
        std::cout << "Your username is: " << username << "!" << std::endl;
    }
}
