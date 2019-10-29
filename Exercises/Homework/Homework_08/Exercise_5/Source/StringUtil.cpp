#include "StringUtil.h"
#include <sstream>

std::vector<std::string> StringUtil::split(const std::string& sentence, const char delimiter)
{
    std::vector<std::string> words;
    std::string word;

    std::istringstream sentence_stream(sentence);

    while (std::getline(sentence_stream, word, delimiter)) {
        words.emplace_back(word);
    }

    return words;
}