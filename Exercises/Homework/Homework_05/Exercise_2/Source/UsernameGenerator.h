#ifndef USERNAME_GENERATOR_H
#define USERNAME_GENERATOR_H

#include <string>

class UsernameGenerator {
public:
    static std::string generate(const std::string& email, const int birth_year);
};

#endif