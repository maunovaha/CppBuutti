#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>

class Alphabet {
public:
    static std::vector<char> all_letters();
    static std::vector<char> between(const char start, const char end);
private:
    inline static const std::vector<char> alphabet_{between('a', 'z')};
};

#endif