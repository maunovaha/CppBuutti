#include "Application.h"
#include "InputReader.h"
#include "StringManipulator.h"
#include <string>
#include <iostream>

Application::Application()
{
    run();
}

void Application::run() const
{
    for (;;) {
        std::cout << "Write a text:" << std::endl;
        const std::string text = InputReader::read_str();

        std::cout << "How much do you want to shift? e.g. type 5" << std::endl;
        const int shift_amount = InputReader::read_int();
        
        const std::string caesar_cipher = StringManipulator::to_caesar_chiper(text, shift_amount);
        std::cout << "\n*****************************************************"
                  << "\nThe caesar cipher for \"" << text << "\" is \"" << caesar_cipher << "\""
                  << "\n*****************************************************\n\n";
    }
}
