# Lecture 3

> This lecture discusses loops.

## Exercise 1

> Create a program that takes in a number *n* and prints out a trinalge of &'s with the height of *n*.
> 
> For example, if *n* is 4, program prints:  
> &  
> &&  
> &&&  
> &&&&

```cpp
#include <iostream>
#include <string>

void print_triangle(const int n, const char shape = '&')
{
    std::string line{shape};

    for (int i = 0; i < n; ++i, line += shape) {
        std::cout << line << std::endl;
    }
}

int main()
{
    int n = 0;

    std::cout << "Give me the value of n: " << std::endl;

    if (std::cin >> n) {
        print_triangle(n);
    }
    else {
        std::cout << "Invalid data! Try again." << std::endl;
        return -1;
    }

    return 0;
}
```

## Exercise 2a

> Find out how many numbers you have to add together for the result to be over *1000*. e.g. *(1 + 2 + 3 + 4 + 5 = 15)*.

```cpp
#include <iostream>

int main()
{
    const int limit = 1000;
    
    int increment = 0;
    int current = 0;

    for (;;) {
    	++increment;
        current += increment;

        std::cout << "The value of current is: " << current << std::endl;

        if (current >= limit) {
            std::cout << "\nWe looped " << increment << " times!" << std::endl;
            break;
        }
    }

    return 0;
}
```

The answer is 45 numbers.

## Exercise 2b

> Adding to the previous experiment. Find out how many numbers you have to add together for the result to be over *1000*, but skip all numbers - using *continue* statement - that are multiples of *3*. e.g. *(3, 6, 9, 12, 15, 18...)*.

```cpp
#include <iostream>

bool is_multiple_of_three(const int value) 
{
    return value % 3 == 0;
}

int main()
{
    const int limit = 1000;

    int increment = 0;
    int current = 0;

    for (;;) {
        ++increment;

        if (is_multiple_of_three(increment)) {
            continue;
        }
 
        current += increment;

        std::cout << "The value of current is: " << current << std::endl;

        if (current >= limit) {
            std::cout << "\nWe looped " << increment << " times!" << std::endl;
            break;
        }
    } 

    return 0;
}
```

The answer is 55 numbers.
