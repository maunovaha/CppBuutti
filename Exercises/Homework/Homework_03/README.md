# Homework 3

## Exercise 1

> Make a program that asks you inside an infinite while loop to input a number between *4* to *10*, but if you input another number, such as *3*, *-1* or *12*, it repeats until you do.
> 
> Example output =>  
> *Give a number between 4 - 10:*  
> *10*   
> *Give a number between 4 - 10:*  
> *2*  
> *Give a number between 4 - 10:*  
> *6*  
> *Number 6 is a good number!*

```cpp
#include <iostream>

int main()
{
    const int min = 4;
    const int max = 10;

    int number = 0;

    while (number < min + 1 || number > max - 1) {
        std::cout << "Give a number between " << min << " - " << max << ":" << std::endl;

        if (!(std::cin >> number)) {
            // In case of cin error, we need to clear the failed state of stream, as well as
            // discard unprocessed characters. Otherwise, we will get an infinite loop when 
            // user enters something else than number, such as letter "x".
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    std::cout << "Number " << number << " is a good number!" << std::endl;

    return 0;
}
```

## Exercise 2

> In the following program, fill in the *-----* to make a *for loop* that goes through every second number from *100* to *0*.
> 
> ```  
> for(-----) {  
>     std::cout << -----;  
> }  
> ```
> 
> Example output =>  
> *100*  
> *96*  
> *94*  
> *...*  
> *4*  
> *2*  
> *0*  

```cpp
#include <iostream>

int main()
{
    for (int i = 100; i >= 0; i -= 2) {
        std::cout << i << std::endl;
    }

    return 0;
}
```

## Exercise 3

> FizzBuzz is a classic interview coding question. It goes in the following way:
> 
> Go through all numbers from *0* to *100*.  
> If the number is divisible by *3*, e.g. *(3, 6, 9, 12, 15...)*, then print *Fizz*.  
> If the number is divisible by *5*, e.g. *(5, 10, 15, 20...)*, then print *Buzz*.  
> If the number is divisible by *15*, then print *FizzBuzz*.  
> If the number is not divisible by *3* or *5* print the number itself.
> 
> Example output =>  
> *1*  
> *2*  
> *Fizz*  
> *4*  
> *Buzz*  
> *Fizz*  
> *7*  
> *8*  
> *Fizz*  
> *Buzz*  
> *11*  
> *Fizz*  
> *13*  
> *14*  
> *FizzBuzz*  
> *16*  
> *...*  

```cpp
#include <iostream>
#include <string>

bool is_fizz(const int value)
{
    return value % 3 == 0;
}

bool is_buzz(const int value)
{
    return value % 5 == 0;
}

std::string to_fizzbuzz(const int value)
{
    std::string words;

    if (is_fizz(value)) {
        words += "Fizz";
    }

    if (is_buzz(value)) {
        words += "Buzz";
    }

    return words.empty() ? std::to_string(value) : words;
}

int main()
{
    for (int i = 1; i <= 100; ++i) {
        std::cout << to_fizzbuzz(i) << std::endl;
    }

    return 0;
}
```

## Exercise 4

> Print the following structure:
> 
> *1234567*  
> *2345678*  
> *3456789*  
> *4567890*  
> *5678901*  
> *6789012*  
> *7890123*  
> *...*
> 
> Until *10* using *two loops*, one inside another.
> 
> Instead of number *10*, input the number as an argument from the command line, for example: ```./main 7``` should print the square above.

```cpp
#include <iostream>
#include <string>
#include <stdexcept>

void print_number_square(const int size, const int first_number = 1)
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0, number = first_number; j < size; ++j, ++number) {
            std::cout << (i + number) % 10;
        }
        std::cout << "\n";
    }
}

int main(int argv, char* argc[])
{
    try {
        const int size = std::stoi(argc[1]);
        print_number_square(size);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error! Did you run the program correctly? "
            << "e.g. Try something like: `./main 7`\n\n" 
            << "Detailed error: \"" << e.what() << "\"" << std::endl;
    }

    return 0;
}
```

## Exercise 5

> Print all prime numbers that are under *100*. A primer number is a number that can't be divided by any other number than *1* or the number itself.
>
> *10* can be divided by *2* and *5* and it not a primer number.
>
> *11* can not be divided by numbers other than *1* or *11*, and therefore, is a primer number.
>
> Example output =>  
> *2*  
> *3*  
> *5*  
> *7*  
> *11*  
> *13*  
> *17*  
> *19*  
> *23*  
> *29*  
> *...*

```cpp
#include <iostream>

void print_prime_numbers(const int until)
{
    int number, divider;

    for (number = 2; number <= until; ++number) {
        for (divider = 2; divider < number; ++divider) {
            if (number % divider == 0) {
                break;
            }
        }
        if (number == divider) {
            std::cout << number << std::endl;
        }
    }
}

int main()
{
    print_prime_numbers(100);

    return 0;
}
```

## Exercise 6 (todo later)

> ... 

```cpp
```

## Exercise 7 (todo later)

> ... 

```cpp
```