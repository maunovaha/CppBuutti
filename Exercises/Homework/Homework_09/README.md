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
>
> **NOTE:** In place of *map* I decided to use *array* because *map* contains <key, value> -pairs so it would have been troublesome.)

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <sstream>

class Random {
public:
    Random() = delete;
    static std::mt19937& generator()
    {
        static std::mt19937 mt_rand(std::time(nullptr));
        return mt_rand;
    }
};

template <typename T>
void shuffle_container(T& container)
{
    std::shuffle(container.begin(), container.end(), Random::generator());
}

template <typename T>
std::string to_str(const T& value, const int precision = 2)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << value;

    return stream.str();
}

template <typename T>
std::string to_sentence(const T& container)
{
    std::string str;

    for (int i = 0; i < container.size(); ++i) {
        str += to_str(container.at(i));

        if (i < container.size() - 1) {
            str += ", ";
        }
    }

    return str;
}

template <typename T>
void print_and_shuffle(T& container)
{
    std::cout << "Shuffling \"" << to_sentence(container) << "\" results to \"";

    shuffle_container(container);

    std::cout << to_sentence(container) << "\"\n";
}

int main()
{
    std::vector<int> grades = {1, 2, 3, 4, 5};
    std::array<float, 3> temperatures = {-11.4, 32.2f, 45.4};
    std::string alphabet = "abcdef";

    print_and_shuffle(grades);
    print_and_shuffle(temperatures);
    print_and_shuffle(alphabet);

    return 0;
}
```

**Output**

```
Shuffling "1, 2, 3, 4, 5" results to "4, 3, 2, 1, 5"
Shuffling "-11.40, 32.20, 45.40" results to "-11.40, 45.40, 32.20"
Shuffling "a, b, c, d, e, f" results to "e, b, d, f, c, a"
```

## Exercise 4

> Make your own class *NatoAlphabet* that holds a *std::string* and casts chars and *std::strings* into *NatoAlphabet* type. And *NatoAlphabet* into strings and chars.

```cpp
```