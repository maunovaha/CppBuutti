#include "Application.h"
#include "Lottery.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Application::Application()
{
    run();
}

void Application::run() const
{
    srand(time(0));
    print_lottery_numbers(Lottery::draw());
}

void Application::print_lottery_numbers(const std::set<int>& lottery_numbers) const
{
    std::cout << "Your lottery numbers are: ";

    int counter = 0;

    for (const int& number : lottery_numbers) {
        std::cout << number;

        if (counter < lottery_numbers.size() - 1) {
            std::cout << ", ";
        }

        ++counter;
    }

    std::cout << std::endl;
}