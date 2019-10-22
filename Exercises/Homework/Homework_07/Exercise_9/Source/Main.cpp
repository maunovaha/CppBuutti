#include "Book.h"

int main()
{
    Book book{"Data/ebook_of_dracula_by_bram_st.txt"};
    book.display_top_words(20);

    return 0;
}