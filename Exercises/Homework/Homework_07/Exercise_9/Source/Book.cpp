#include "Book.h"
#include "FileReader.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

Book::Book(const std::string& file_name) : words_count_{FileReader::read(file_name)}
{
}

void Book::display_top_words(const int limit) const
{
    std::cout << "===============================================\n"
              << "Top " << limit << " most used words in the book\n"
              << "===============================================\n";

    int counter{};

    auto sort_by_count = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
    {
        return a.second > b.second;
    };

    std::vector<std::pair<std::string, int>> words_count(words_count_.begin(), words_count_.end());
    std::sort(words_count.begin(), words_count.end(), sort_by_count);

    for (const auto& word : words_count) {
        std::cout << "\"" << word.first << "\" appears " << word.second << " times." << std::endl;

        if (counter > limit) {
            break;
        }

        ++counter;
    }
}
