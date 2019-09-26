# Lecture 1

> This lecture discusses about variables, types, operations and handling text i/o.

## Exercise 1

> Create a program to try out all the variable types: *bool*, *int*, *float*, *double* and *char*. Print these values using *std::cout*.

```cpp
#include <iostream>
#include <iomanip>

int main()
{
    // Variables are declared as `const` because they do not change during
    // the execution of the program.
    const int age = 32;
    const char letter = 'A';
    const bool valid = false;
    const float distance = 22.123456789F;
    const double length = 22.123456789;
    
    std::cout << "Variable age value is: " << age << std::endl;
    std::cout << "Variable letter value is: " << letter << std::endl;
    std::cout << "Variable valid value is: " << valid << std::endl;
    std::cout << "Variable distance value is: " << distance << std::endl;
    std::cout << "Variable length value is: " << length << std::endl;

    // Using i/o manipulators such as `std::boolalpha` and `std::setprecision` we can further 
    // control how the output is presented to the user. Hence, if they are not unset, they will
    // apply to all further output values of `std::cout`.
    //
    // `std::boolalpha`    => Allows to output textual value of bool (`false` in this case)
    // `std::setprecision` => Allows to round floating point numbers (e.g. `float` and `double`)
    std::cout << "\n--- After applying i/o manipulators ---\n" << std::endl;
    std::cout << std::boolalpha << std::setprecision(4);

    std::cout << "Variable valid value is: " << valid << std::endl;
    std::cout << "Variable distance value is: " << distance << std::endl;
    std::cout << "Variable length value is: " << length << std::endl;

    return 0;
}
```

**Output**

```
Variable age value is: 32
Variable letter value is: A
Variable valid value is: 0
Variable distance value is: 22.1235
Variable length value is: 22.1235

--- After applying i/o manipulators ---

Variable valid value is: false
Variable distance value is: 22.12
Variable length value is: 22.12
```