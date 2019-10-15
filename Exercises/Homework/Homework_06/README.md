# Homework 6

## Exercise 1

> Make a *for loop* that counts all numbers from *1* to *100* but for odd numbers multiplies them by itself instead.

```cpp
#include <iostream>

bool is_odd(const int number)
{
    return number % 2 != 0;
}

int multiply_odd_number(const int number)
{
    return is_odd(number) ? (number * number) : number;
}

int main()
{
    const int min = 1;
    const int max = 100;

    for (int number = min; number <= max; ++number) {
        std::cout << multiply_odd_number(number) << " ";
    }

    std::cout << std::endl;

    return 0;
}
```

**Output**

```
1 2 9 4 25 6 49 8 81 10 121 12 169 14 225 16 289 18 361 20 441 22 529 24 625 26 729 28 841 30 961 32 1089 34 1225 36 1369 38 1521 40 1681 42 1849 44 2025 46 2209 48 2401 50 2601 52 2809 54 3025 56 3249 58 3481 60 3721 62 3969 64 4225 66 4489 68 4761 70 5041 72 5329 74 5625 76 5929 78 6241 80 6561 82 6889 84 7225 86 7569 88 7921 90 8281 92 8649 94 9025 96 9409 98 9801 100
```

## Exercise 2

> Fill an *std::array* of length *10* with numbers *2, 4, 6, 8...* and so on using a *for loop*. Use *for loop* with *range operator :* to print out the loop in the end of a program.

```cpp
#include <iostream>
#include <array>
#include <cstddef>

template<std::size_t N>
void fill_array(std::array<int, N>& container)
{
    for (int i = 0; i < container.size(); ++i) {
        container.at(i) = (i + 1) * 2;
    }
}

template<std::size_t N>
void print_array(const std::array<int, N>& container)
{
    for (const auto& number : container) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 10> numbers;

    fill_array(numbers);
    print_array(numbers);

    return 0;
}
```

**Output**

```
2 4 6 8 10 12 14 16 18 20
```

## Exercise 3

> Make a function that takes in a *vector*. Increase all numbers in the *vector* by *10* inside a *for loop*. Call your function in *main* and print the numbers (also in *main*). Remember to use references to not make copies!

```cpp
#include <iostream>
#include <vector>

void increment_numbers(std::vector<int>& numbers, const int increment)
{
    for (auto& number : numbers) {
        number += increment;
    }
}

void print_numbers(const std::vector<int>& numbers)
{
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n" << std::endl;
}

int main()
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Numbers before: " << std::endl;
    print_numbers(numbers);

    increment_numbers(numbers, 10);

    std::cout << "Numbers after: " << std::endl;
    print_numbers(numbers);

    return 0;
}
```

**Output**

```
Numbers before: 
1 2 3 4 5 6 7 8 9 10 

Numbers after: 
11 12 13 14 15 16 17 18 19 20
```

## Exercise 4

> Make a *std::set* of *fruits* and put *banana*, *apple* and *peach* inside. Find out using google how to put a new item in *std::set*. Make an *infinite loop* where you can add fruits by your input and it keeps printing out the entire set every time.
> 
> Example output =>  
> *The fruits basked contains apple, banana, peach. Tell me more fruits?*  
> *kiwi*  
> *The fruits basked contains apple, banana, kiwi, peach. Tell me more fruits?*  
> *apricot*  
> *The fruits basked contains apple, apricot, banana, kiwi, peach. Tell me more fruits?*

```cpp
#include <iostream>
#include <set>
#include <string>
#include <utility>

void print_fruits_basked(const std::set<std::string>& fruits_basked)
{
    if (fruits_basked.empty()) {
        std::cout << "The fruits basked is empty!" << std::endl;
        return;
    }

    std::cout << "The fruits basked contains ";

    int counter = 0;

    for (const auto& fruit : fruits_basked) {
        std::cout << fruit;

        if (counter < fruits_basked.size() - 1) {
            std::cout << ", ";
        }

        ++counter;
    }

    std::cout << ". Tell me more fruits?" << std::endl;
}

std::string read_fruit()
{
    std::string fruit;
    std::getline(std::cin, fruit);

    return std::move(fruit);
}

int main()
{
    std::set<std::string> fruits_basked{"banana", "apple", "peach"};
    print_fruits_basked(fruits_basked);

    for (;;) {
        const std::string fruit = read_fruit();
        fruits_basked.insert(fruit);

        print_fruits_basked(fruits_basked);
    }

    return 0;
}
```
