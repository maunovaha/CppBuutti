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

## Exercise 3

> Write a recursive program that calculates the **_factorial_** *n!* of a given number *n*.
> 
> _n! = n * (n - 1) * (n - 2) * ... * 1_  
> _if n = 4, factorial n! = 4 * 3 * 2 * 1_

```cpp
#include <iostream>

int factorial(const int n)
{
    if (n <= 1) {
        return n;
    }

    // When this part of the code executes recursively, and the value of `n` is 4; The program
    // executes as follows:
    // 
    // return 4 * factorial(4 - 1);
    // return 4 * 3 * factorial(3 - 1);
    // return 4 * 3 * 2 * factorial(2 - 1);
    // return 4 * 3 * 2 * 1; // The returned value is 24 when `n` is 4 (which is correct!).
    return n * factorial(n - 1);
}

int main()
{
    std::cout << "The factorial(0) is: " << factorial(0) << "\n"
              << "The factorial(1) is: " << factorial(1) << "\n"
              << "The factorial(2) is: " << factorial(2) << "\n"
              << "The factorial(3) is: " << factorial(3) << "\n"
              << "The factorial(4) is: " << factorial(4) << "\n"
              << "The factorial(5) is: " << factorial(5) << "\n"
              << "The factorial(6) is: " << factorial(6) << "\n"
              << "The factorial(7) is: " << factorial(7) << "\n"
              << "The factorial(8) is: " << factorial(8) << "\n"
              << "The factorial(9) is: " << factorial(9) << std::endl;

    return 0;
}
```

**Output**

```
The factorial(0) is: 0
The factorial(1) is: 1
The factorial(2) is: 2
The factorial(3) is: 6
The factorial(4) is: 24
The factorial(5) is: 120
The factorial(6) is: 720
The factorial(7) is: 5040
The factorial(8) is: 40320
The factorial(9) is: 362880
```

## Exercise 4

> **_Collatz conjecture:_**  
> Define a number *n* that is larger than *0*, e.g. *n = 3*.  
> Then find the number of steps it takes to reach number *1* using the following process:  
> If *n* is even, divide it by *2*.  
> If *n* is odd, multiply it by *3* and add *1*.
>
> Example output =>  
> *Please give a whole number:*  
> *3*  
> *3 is odd.*  
> *10 is even.*  
> *5 is odd.*  
> *16 is even.*  
> *8 is even.*  
> *4 is even.*  
> *2 is even.*
> 
> *The program executed 7 step(s) to reach number 1*.

```cpp
#include <iostream>

bool is_odd(const int value)
{
    return value % 2 != 0;
}

int collatz_conjecture(const int value, int steps = 0)
{
    if (value <= 1) {
        return steps;
    }

    ++steps;

    if (is_odd(value)) {
        std::cout << value << " is odd." << std::endl;
        return collatz_conjecture(value * 3 + 1, steps);
    } 
    else {
        std::cout << value << " is even." << std::endl;
        return collatz_conjecture(value / 2, steps);
    }
}

int main()
{
    std::cout << "Please give a whole number: " << std::endl;

    int number = 0;

    if (std::cin >> number) {
        const int steps = collatz_conjecture(number);
        std::cout << "The program executed " << steps << " step(s) to reach number 1." << std::endl;
    }
    else {
        std::cout << "Invalid data! Try again." << std::endl;
        return -1;
    }

    return 0;
}
```
