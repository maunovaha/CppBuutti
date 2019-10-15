#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

class Vector {
public:
    static int index_of(const char letter, const std::vector<char>& letter_list);
    static std::vector<char> shift(const std::vector<char>& letter_list, const int shift_amount);
};

#endif
