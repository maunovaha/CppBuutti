#include "UsernameGenerator.h"
#include <utility>

std::string UsernameGenerator::generate(const std::string& email, const int birth_year)
{
    std::string year = std::to_string(birth_year);
    std::string username = email + year.substr(2, 4);

    return std::move(username);
}