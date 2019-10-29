# Homework 9

## Exercise 1

> Randomize a coin flip. If the "coin flip" is heads; Flip the coin again until it is tails. Print how many times the computer managed to flip the coin as heads in a row.
>
> Example output =>  
> *The computer flipped heads 3 times before getting tails!*

```cpp
#include <iostream>
#include <random>
#include <ctime>

class RandomNumber {
public:
    RandomNumber() = delete;
    static int between(const int min, const int max)
    {
        static std::mt19937 mt_rand(std::time(nullptr));

        return min + mt_rand() % ((max + 1) - min);
    }
};

class Coin {
public:
    static Coin flip()
    {
        return {RandomNumber::between(heads_, tails_)};
    }

    bool is_tails() const
    {
        return value_ == tails_;
    }
private:
    Coin(const int value) : value_{value}
    {
    }

    const int value_;
    inline static const int heads_ = 0;
    inline static const int tails_ = 1;
};

int main()
{
    int heads_count = 0;

    for (;;) {
        const Coin flipped_coin = Coin::flip();

        if (flipped_coin.is_tails()) {
            break;
        }

        ++heads_count;
    }

    std::cout << "The computer flipped heads " << heads_count << " times before getting tails!\n";

    return 0;
}
```

## Exercise 2

> Make a function that uses a *for loop* and a *std::vector<int>* and returns the largest number from the *vector*.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int get_largest_number(const std::vector<int>& numbers)
{
    // Alternative (better) way of doing this, but using for loop because the exercise told so.
    // return *std::max_element(numbers.begin(), numbers.end());

    int largest_number{};

    for (const auto& number : numbers) {
        if (number > largest_number) {
            largest_number = number;
        }
    }

    return largest_number;
}

int main()
{
    const std::vector<int> v1 = {1, 4, 2, 3};
    const std::vector<int> v2 = {0, 1, 2, 3};
    const std::vector<int> v3 = {5, 4, 3, 1};

    std::cout << "Largest number in vector: \"{1, 4, 2, 3}\" is \"" << get_largest_number(v1) << "\"\n";
    std::cout << "Largest number in vector: \"{0, 1, 2, 3}\" is \"" << get_largest_number(v2) << "\"\n";
    std::cout << "Largest number in vector: \"{5, 4, 3, 1}\" is \"" << get_largest_number(v3) << "\"\n";

    return 0;
}
```

**Output**

```
Largest number in vector: "{1, 4, 2, 3}" is "4"
Largest number in vector: "{0, 1, 2, 3}" is "3"
Largest number in vector: "{5, 4, 3, 1}" is "5"
```

## Exercise 3

> Make a function that makes a new random generator and *std::shuffles* any type of container (test with *string*, *vector* and *map*) using templates.

```cpp
```

## Exercise 4

> Make your own class *NatoAlphabet* that holds a *std::string* and casts chars and *std::strings* into *NatoAlphabet* type. And *NatoAlphabet* into strings and chars.

```cpp
```