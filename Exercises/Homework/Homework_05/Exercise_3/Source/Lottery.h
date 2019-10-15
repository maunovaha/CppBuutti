#ifndef LOTTERY_H
#define LOTTERY_H

#include <set>

class Lottery {
public:
    static std::set<int> draw(const int number_count = number_count_, 
                              const int min = min_, 
                              const int max = max_);
private:
    inline static const int number_count_ = 7;
    inline static const int min_ = 1;
    inline static const int max_ = 39;
};

#endif