# Lecture 3

> This lecture discusses loops.

## Exercise 1

> Create a program that takes in a number `n` and prints out a trinalge of &'s with the height of `n`.
> 
> For example, if `n` is 4, program prints:  
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
