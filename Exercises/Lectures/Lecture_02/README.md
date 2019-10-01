# Lecture 2

> This lecture discusses about functions, conditions and conditionals.

## Exercise 1

> Create two functions; The first one takes in two *int* parameters, multiplies them, and returns the result. The second one takes in one parameter, prints its value to a console, and returns nothing.
> 
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

> Create a program that takes in three numbers *a*, *b* and *c* (decide the value for these freely). Then find the largest number among these three using *if* conditionals. Finally, print the result to a console.

```cpp
#include <iostream>

int main()
{
    std::cout << "Give values for a, b and c separated by spaces: " << std::endl;
    int a = 0;
    int b = 0;
    int c = 0;
    
    if (!(std::cin >> a >> b >> c)) {
        std::cout << "Invalid data! Try again." << std::endl;
        return -1;
    }

    // Note: The program assumes that the user provides values which are not the same. However,
    // we use `>=` here to handle equal cases as well.

    if (a >= b && a >= c) {
        std::cout << "a is the largest number!" << std::endl;
    }
    else if (b >= a && b >= c) {
        std::cout << "b is the largest number!" << std::endl;
    }
    else {
        std::cout << "c is the largest number!" << std::endl;
    }

    return 0;
}
```

## Exercise 3

> Create a program where you define the following: *str1*, *str2* and the combined string *str1 + str2*.
> 
> Check the length of these strings using *size()*, e.g. *str1.size()* or *str2.size()*.
> 
> Then create three if statements where you check the string length of *str1*, *str2* and the combined string, and *only* print the strings if their length is smaller than *8*.

```cpp
#include <iostream>
#include <string>

int main()
{
    const int max_str_size = 8;

    std::cout << "Give value of str1:" << std::endl;
    std::string str1;
    std::cin >> str1;

    std::cout << "Give value of str2:" << std::endl;
    std::string str2;
    std::cin >> str2;

    const std::string str3 = str1 + str2;

    if (str1.size() < max_str_size) {
        std::cout << "The size of str1 is: " << str1.size() << std::endl;
    }

    if (str2.size() < max_str_size) {
        std::cout << "The size of str2 is: " << str2.size() << std::endl;
    }

    if (str3.size() < max_str_size) {
        std::cout << "The size of str3 is: " << str3.size() << std::endl;
    }

    return 0;
}
```
