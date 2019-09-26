# Homework 1

## Exercise 1

> Make an application that asks for your birth year and prints out how many years old you will be at the end of the year.
> 
> Example output =>  
> *What is your birth year?*  
> *1989*  
> *You will be 30 years old this year!*

```cpp
#include <iostream>

int main()
{
    const int current_year = 2019;

    std::cout << "What is your birth year?" << std::endl;

    int birth_year = 0;

    if (std::cin >> birth_year) {
        // Normally we would have more validations here, but in order to keep things simple
        // we assume that the user just provides a proper birth year.

        int age = current_year - birth_year;
        
        std::cout << "You will be " << age << " years old this year!" << std::endl;
    }
    else {
        std::cout << "Invalid data? Try again." << std::endl;
        return -1;
    }

    return 0;
}
```
