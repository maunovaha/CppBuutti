#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <string>

class InputReader {
public:
    static std::string read_str();
    static bool read_int(int& value, const int min, const int max);
private:
    static void reset();
};

#endif
