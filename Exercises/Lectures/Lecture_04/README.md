# Lecture 4

> This lecture discusses structs and constants.

## Exercise 1

> Create a *Playing_card* struct; This struct should have *two* properties: Its *suit* as a *std::string (hearts, diamonds, clubs, spades)*, and its *value* as an *int (1 - 13)*.
>
> Create a function that prints the data of the playing card in the following format:
> 
> *4 of clubs*  
> *Ace of spades*  
> *Queen of hearts*
>
> Remember to include special conditions for *Ace (1), Jack (11), Queen(12)* and *King(13)*.

```cpp
#include <iostream>
#include <string>
#include <array>

struct Playing_card {
    int value = 0;
    std::string suit;
};

void print_playing_card(const Playing_card& playing_card)
{
    if (playing_card.value > 1 && playing_card.value < 11) {
        std::cout << playing_card.value << " of " << playing_card.suit << std::endl;
    }
    else if (playing_card.value == 1) {
        std::cout << "Ace of " << playing_card.suit << std::endl;
    }
    else if (playing_card.value == 11) {
        std::cout << "Jack of " << playing_card.suit << std::endl;
    }
    else if (playing_card.value == 12) {
        std::cout << "Queen of " << playing_card.suit << std::endl;
    }
    else if (playing_card.value == 13) {
        std::cout << "King of " << playing_card.suit << std::endl;
    }
}

int main()
{
    const std::array<std::string, 4> suits = {"hearts", "diamonds", "clubs", "spades"};
    const int cards_per_suit = 13;

    for (auto suit_it = suits.begin(); suit_it != suits.end(); ++suit_it) {
        for (int value = 1; value < cards_per_suit + 1; ++value) {
            print_playing_card({.value = value, .suit = *suit_it});
        }

        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
```

**Output**

```
Ace of hearts
2 of hearts
3 of hearts
4 of hearts
5 of hearts
6 of hearts
7 of hearts
8 of hearts
9 of hearts
10 of hearts
Jack of hearts
Queen of hearts
King of hearts
------------------------
Ace of diamonds
2 of diamonds
3 of diamonds
4 of diamonds
5 of diamonds
6 of diamonds
7 of diamonds
8 of diamonds
9 of diamonds
10 of diamonds
Jack of diamonds
Queen of diamonds
King of diamonds
------------------------
Ace of clubs
2 of clubs
3 of clubs
4 of clubs
5 of clubs
6 of clubs
7 of clubs
8 of clubs
9 of clubs
10 of clubs
Jack of clubs
Queen of clubs
King of clubs
------------------------
Ace of spades
2 of spades
3 of spades
4 of spades
5 of spades
6 of spades
7 of spades
8 of spades
9 of spades
10 of spades
Jack of spades
Queen of spades
King of spades
------------------------
```

## Exercise 2

> Create a program in which you have a function that increments the value which is passed in. (Note: The function should use *void* as a return type).

```cpp
#include <iostream>

void change_year(int& year)
{
    ++year;
}

int main()
{
    int year = 2019;

    std::cout << "The current year is: " << year << std::endl;

    change_year(year);

    std::cout << "The current year is: " << year << std::endl;

    return 0;
}
```

**Output**

```
The current year is: 2019
The current year is: 2020
```

## Exercise 3

> ...

```cpp
```

## Exercise 4

> ...

```cpp
```
