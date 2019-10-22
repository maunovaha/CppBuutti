#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <unordered_map>

class FileReader {
public:
    static std::unordered_map<std::string, int> read(const std::string& file_name);
};

#endif