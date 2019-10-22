#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <unordered_map>

class Book {
public:
    Book(const std::string& file_name);
    void display_top_words(const int limit = 20) const;
private:
    std::unordered_map<std::string, int> words_count_;
};

#endif