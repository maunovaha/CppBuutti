#include "FileReader.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

std::unordered_map<std::string, int> FileReader::read(const std::string& file_name)
{
    std::fstream file_stream;
    file_stream.open(file_name, file_stream.in);

    if (!file_stream.is_open()) {
        throw std::runtime_error("Cannot open " + file_name + " for reading!");
    }

    std::unordered_map<std::string, int> words;

    while (!file_stream.eof()) {
        std::string word;
        file_stream >> word;

        std::transform(word.begin(), word.end(), word.begin(), [](char letter)
        {
            return std::tolower(letter);
        });

        if (words.find(word) != words.end()) {
            words[word] = ++words.at(word);
        }
        else {
            words.emplace(word, 1);
        }
    }

    return words;
}
