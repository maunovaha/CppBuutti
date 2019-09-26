# Lecture 2

> This lecture discusses about functions, conditions and conditionals.

## Exercise 1

> Create two functions; The first one takes in two *int* parameters, multiplies them, and returns the result. The second one takes in one parameter, outputs its value to the console, and returns nothing.
> Note: Use the first function to get a value which you then pass into the second function.

```cpp
#include <iostream>

int multiply(const int a, const int b)
{
    return a * b;
}

void print(const int value)
{
    std::cout << "The value is: " << value << std::endl;
}

int main()
{
    print(multiply(1, 100));
    print(multiply(2, 100));
    print(multiply(3, 100));

    return 0;
}
```

**Output**

```
The value is: 100
The value is: 200
The value is: 300
```

## Exercise 2

> ...

```cpp
```

## Exercise 3

> ...

```cpp
```