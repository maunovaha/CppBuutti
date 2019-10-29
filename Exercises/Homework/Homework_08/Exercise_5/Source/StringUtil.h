#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <string>
#include <vector>

class StringUtil {
public:
    StringUtil() = delete;
    static std::vector<std::string> split(const std::string& sentence, const char delimiter);
};

#endif