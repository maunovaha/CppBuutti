#ifndef APPLICATION_H
#define APPLICATION_H

#include <set>

class Application {
public:
    Application();
private:
    void run() const;
    void print_lottery_numbers(const std::set<int>& lottery_numbers) const;
};

#endif