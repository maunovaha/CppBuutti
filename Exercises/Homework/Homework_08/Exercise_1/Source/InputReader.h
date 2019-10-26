#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <iostream>
#include <string>

class InputReader {
public:
    InputReader() = delete;

    template <typename T>
    static T read(const std::string& error_message)
    {
        T input{};

        const bool valid_input = read_once(input);

        if (!valid_input) {
            std::cerr << error_message << std::endl;
            return read<T>(error_message);
        }

        return input;
    }

    template <typename T>
    static bool read_once(T& input)
    {
        const bool valid_input = static_cast<bool>(std::cin >> input);
        reset();

        return valid_input;
    }
private:
    static void reset();
};

#endif