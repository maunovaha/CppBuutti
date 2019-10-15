#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <string>

class InputReader {
public:
    static std::string read_str();
    static int read_int();
    static bool read(int& value);
private:
    static void reset();
};

#endif
