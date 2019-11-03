# Homework 10

## Exercise 1

> Given all integers between *0* and *50*. Count how many ones (number *1* that is) the number has in binary. If the amount is *even* print the number. Otherwise don't print it. There is a binary converter in the lecture material.
>
> Example output =>  
> *0 3 5 6 9 10 12 15 17 18 20 23 24 27 29 30 33 34 36 39 40 43 45 46 48*

```cpp
#include <iostream>
#include <string>

std::string binary_number_to_str(const uint8_t binary_number)
{
    std::string binary_as_str{"0b"}; // "0b" means zero binary
    const int bit_count = 8;

    for (int i = 0; i < bit_count; ++i) {
        const int bs = (bit_count - 1) - i;
        binary_as_str += std::to_string(static_cast<int>((binary_number & (1 << bs)) >> bs));
    }

    return binary_as_str;
}

int get_bit_value_count(const uint8_t binary_number, const char bit_value) {
    const std::string binary_as_str = binary_number_to_str(binary_number);

    int bit_value_count{};

    for (const auto& value : binary_as_str) {
        if (value == bit_value) {
            ++bit_value_count;
        }
    }

    return bit_value_count;
}

bool is_even(const int value){
    return value % 2 == 0;
}

int main()
{
    const int min = 0;
    const int max = 50;

    for (int i = min; i < max; ++i) {
        const int number_one_count = get_bit_value_count(i, '1');

        if (is_even(number_one_count)) {
            std::cout << i << " ";
        }
    }

    std::cout << "\n";

    return 0;
}
```

## Exercise 2

> Asks for user's *full_name* and *birth_year* in *main*. Make a function that creates a *Person struct*. Check when creating the *struct* that your data makes sense, so if e.g. name's length is *0* or birth year isn't between *1900* and *2019* then return a *null pointer* instead.
>
> In *main* call this function with the parameters you got from input and check with "if" if the function returned *null pointer* or pointer
to the *struct*; If it does, say "Creating person failed", otherwise print "Creating person successful". Remember to use *new* so that your pointer value doesn't get deleted due to the scope.

```cpp
```

## Exercise 3

> ...

## Exercise 4

> ...