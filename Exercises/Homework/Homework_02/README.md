# Homework 2

## Exercise 1

> Create a function that calculates the speed of an object in km/h when it is given distance it moved in meters and time in seconds. Note: *1 m/s is 3.6 km/h*.
> 
> Example output =>  
> *What is the distance that the object moved in meters?*  
> *8*  
> *How many seconds did it take?*  
> *2*  
> *The object speed is 14.4000 km/h.*

```cpp
#include <iostream>
#include <iomanip>

double calculate_speed(const double distance, const double duration)
{
    return distance / duration * 3.6;
}

int main()
{
    std::cout << "What is the distance that the object moved in meters?" << std::endl;
    double distance = 0.0;

    if (!(std::cin >> distance)) {
        std::cout << "Invalid distance! Try again." << std::endl;
        return -1;
    }

    std::cout << "How many seconds did it take?" << std::endl;
    double duration = 0.0;

    if (!(std::cin >> duration)) {
        std::cout << "Invalid duration! Try again." << std::endl;
        return -1;
    }

    const double speed = calculate_speed(distance, duration);

    // Here we use i/o manipulator `std::fixed` and `std::setprecision(4)` to make sure that 
    // leading zeros are printed as well. We do this just for fun.
    std::cout << "The object speed is " << std::fixed << std::setprecision(4) 
        << speed << " km/h." << std::endl;

    return 0;
}
```

## Exercise 2

> Create functions that return *true* or *false* based on the assignment. Print values for all possibilities to check that your logic is correct. The parameter names are in the end in parantheses for first two assignments:
> 
> **_a)_** The game hearts can only be played with four people ```(int player_count)```.  
> **_b)_** Mark is happy whe he is not stressed or if he has ice cream ```(bool stressed, bool has_ice_cream)```.  
> **_c)_** It is beach day if the sun is shining, it is not raining and the temperature is 20 degress celcius or above.  
> **_d)_** Johnny is happy if he has a date either with Cindy or with Mindy on Tuesday night. However, having a date with two girls at the same time causes obvious trouble. Also, staying alone makes Johnny sad.

```cpp
#include <iostream>
#include <string>

bool is_hearts(const int player_count)
{
    return player_count == 4;
}

bool is_mark_happy(const bool stressed, const bool has_ice_cream)
{
    return !stressed || has_ice_cream;
}

bool is_beach_day(const bool sunny, const bool raining, const double temperature)
{
    return sunny && !raining && temperature >= 20;
}

bool is_johnny_happy(const std::string& day, const bool date_with_mindy, const bool date_with_cindy)
{
    return day == "Tuesday" && ((date_with_mindy || date_with_cindy) && !(date_with_mindy && date_with_cindy));
}

int main()
{   
    std::cout << std::boolalpha; // Allows to output textual value of bool

    std::cout << "\nis_hearts(4)  = " << is_hearts(4)
              << "\nis_hearts(6)  = " << is_hearts(6)
              << "\nis_hearts(0)  = " << is_hearts(0)
              << "\nis_hearts(-1) = " << is_hearts(-1) << "\n";

    std::cout << "\nis_mark_happy(false, true)  = " << is_mark_happy(false, true)
              << "\nis_mark_happy(true,  false) = " << is_mark_happy(true, false)
              << "\nis_mark_happy(true,  true)  = " << is_mark_happy(true, true)
              << "\nis_mark_happy(false, false) = " << is_mark_happy(false, false) << "\n";

    std::cout << "\nis_beach_day(true,  false, 20) = " << is_beach_day(true, false, 20)
              << "\nis_beach_day(true,  false, 25) = " << is_beach_day(true, false, 25)
              << "\nis_beach_day(true,  false, 19) = " << is_beach_day(true, false, 19)
              << "\nis_beach_day(false, false, 20) = " << is_beach_day(false, false, 20)
              << "\nis_beach_day(true,  true,  20) = " << is_beach_day(true, true, 20)
              << "\nis_beach_day(false, true,  20) = " << is_beach_day(false, true, 20) << "\n";

    std::cout << "\nis_johnny_happy(\"Tuesday\",   false, true)  = " << is_johnny_happy("Tuesday", false, true)
              << "\nis_johnny_happy(\"Tuesday\",   true,  false) = " << is_johnny_happy("Tuesday",true, false)
              << "\nis_johnny_happy(\"Tuesday\",   true,  true)  = " << is_johnny_happy("Tuesday",true, true)
              << "\nis_johnny_happy(\"Tuesday\",   false, false) = " << is_johnny_happy("Tuesday",false, false)
              << "\nis_johnny_happy(\"Monday\",    false, true)  = " << is_johnny_happy("Monday", false, true)
              << "\nis_johnny_happy(\"Wednesday\", false, true)  = " << is_johnny_happy("Wednesday", false, true)
              << "\nis_johnny_happy(\"Thursday\",  false, true)  = " << is_johnny_happy("Thursday", false, true)
              << "\nis_johnny_happy(\"Friday\",    false, true)  = " << is_johnny_happy("Friday", false, true)
              << "\nis_johnny_happy(\"Saturday\",  false, true)  = " << is_johnny_happy("Saturday", false, true)
              << "\nis_johnny_happy(\"Sunday\",    false, true)  = " << is_johnny_happy("Sunday", false, true) << std::endl;

    return 0;
}
```

**Output**

```
is_hearts(4)  = true
is_hearts(6)  = false
is_hearts(0)  = false
is_hearts(-1) = false

is_mark_happy(false, true)  = true
is_mark_happy(true,  false) = false
is_mark_happy(true,  true)  = true
is_mark_happy(false, false) = true

is_beach_day(true,  false, 20) = true
is_beach_day(true,  false, 25) = true
is_beach_day(true,  false, 19) = false
is_beach_day(false, false, 20) = false
is_beach_day(true,  true,  20) = false
is_beach_day(false, true,  20) = false

is_johnny_happy("Tuesday",   false, true)  = true
is_johnny_happy("Tuesday",   true,  false) = true
is_johnny_happy("Tuesday",   true,  true)  = false
is_johnny_happy("Tuesday",   false, false) = false
is_johnny_happy("Monday",    false, true)  = false
is_johnny_happy("Wednesday", false, true)  = false
is_johnny_happy("Thursday",  false, true)  = false
is_johnny_happy("Friday",    false, true)  = false
is_johnny_happy("Saturday",  false, true)  = false
is_johnny_happy("Sunday",    false, true)  = false
```

## Exercise 3

> Make an application that prints the price of admission to a swimming pool. The application should ask your age and if you are a student. Create a *single* if expression that checks if you are eligible for a discount.
> 
> The pricing table currently looks like this:
> 
> | Group         | Price         |  
> | ------------- |:-------------:|  
> | Adults        | 3.80€         |  
> | Children 0-16 | 2.40€         |  
> | Seniors 65+   | 2.40€         |  
> | Students      | 2.40€         |
> 
> Example output =>  
> *What is your birth year?*  
> *1994*  
> *Are you a student? (y/n)*  
> *y*  
> *Your price of admission is 2.40€*
> 
> *What is your birth year?*  
> *1996*  
> *Are you a student? (y/n)*  
> *n*  
> *Your price of admission is 3.80€*

```cpp
#include <iostream>

int birth_year_to_age(const int birth_year, const int current_year = 2019)
{
    return current_year - birth_year;
}

bool is_child(const int age)
{
    return age > 0 && age <= 16;
}

bool is_senior(const int age)
{
    return age >= 65;
}

bool is_adult(const int age)
{
    return !(is_child(age) || is_senior(age));
}

int main()
{
    const double adults_price = 3.8;
    const double discounted_price = 2.4;

    double current_price = discounted_price;

    std::cout << "What is your birth year?" << std::endl;
    int birth_year = 0;

    if (!(std::cin >> birth_year)) {
        std::cout << "Invalid birth year! Try again." << std::endl;
        return -1;
    }

    const int age = birth_year_to_age(birth_year);

    if (is_adult(age)) {
        std::cout << "Are you a student? (y/n)" << std::endl;
        char student = '\0';

        if (!(std::cin >> student) || !(student == 'y' || student == 'n')) {
            std::cout << "Invalid answer! Try again." << std::endl;
            return -1;
        }

        if (student == 'n') {
            current_price = adults_price;
        }
    }

    std::cout << "Your price of admission is " << current_price << "€" << std::endl;

    return 0;
}

```

## Exercise 4

> Create a simple calculator. First input two numbers. Then ask for the operator (+, -, *, /). Make four functions *calculate_sum*, *calculate_subtraction*, *calculate_multiplication*, and *calculate_division*. Then call them based on what operator was used.
> 
> Don't worry if your division function doesn't work for decimal numbers like *5 / 2*, but if you already know about casting, you can use it.
> 
> Example output =>  
> *What is your first number?*  
> *7*  
> *What is your second number?*  
> *4*  
> _What operand you want to use? (+, -, *, /)_  
> *+*  
> *The result of 7 + 4 is 11.*

```cpp
#include <iostream>
#include <string>

double calculate_sum(const double a, const double b)
{
    return a + b;
}

double calculate_subtraction(const double a, const double b)
{
    return a - b;
}

double calculate_multiplication(const double a, const double b)
{
    return a * b;
}

double calculate_division(const double a, const double b)
{
    return a / b;
}

double calculate_result(const double a, const double b, const char operand)
{
    switch (operand) {
        case '+':
            return calculate_sum(a, b);
        case '-':
            return calculate_subtraction(a, b);
        case '*':
            return calculate_multiplication(a, b);
        case '/':
            return calculate_division(a, b);
    }

    throw std::invalid_argument("Operand you provided is not known!");
}

bool is_valid_operand(const char operand, const std::string& allowed_operands = "+-*/")
{
    return allowed_operands.find(operand) != std::string::npos;
}

int main()
{
    std::cout << "What is your first number?" << std::endl;
    double first = 0.0;

    if (!(std::cin >> first)) {
        std::cout << "Invalid data! Try again." << std::endl;
        return -1;
    }

    std::cout << "What is your second number?" << std::endl;
    double second = 0.0;

    if (!(std::cin >> second)) {
        std::cout << "Invalid data! Try again." << std::endl;
        return -1;
    }

    std::cout << "What operand you want to use? (+, -, *, /)" << std::endl;
    char operand = '\0';

    if (!(std::cin >> operand && is_valid_operand(operand))) {
        std::cout << "Invalid operand! Try again." << std::endl;
        return -1;
    }

    std::cout << "The result of " << first << " " << operand << " " << second
        << " is " << calculate_result(first, second, operand) << "." << std::endl;

    return 0;
}
```

## Exercise 5

> Make a guessing game where the user has to guesss a secret number of your choice.
> 
> **Phase 1:** Make it say if the number is smaller, larger or correct.
> 
> Example output =>  
> *Guess a secret number:*  
> *15*  
> *The secret number is larger!*
>
> *Guess a secret number:*  
> *42*  
> *You found the secret number!*
>
> **Phase 2:** Make it repeat until you find the right answer. *(Tip: You can make a function repeat by calling it in the end of it.)*
>
> **Phase 3:** Use a random number generator to generate the secret number from *0* to *100*. Read the [following theory](http://www.fredosaurus.com/notes-cpp/misc/random.html) on random number generation. *(Tip: Don't make the random number generation repeat!)*

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

int generate_random_number(const int min, const int max)
{
    return min + rand() % ((max + 1) - min);
}

int main()
{
    // Seeding random number generation with the clock in order to ensure that we will 
    // not get same sequence of random numbers when the program is run multiple times.
    srand(time(0));

    const int secret_number = generate_random_number(0, 100);
    int guessed_number = -1;

    do {
        std::cout << "Guess a secret number:" << std::endl;

        if (!(std::cin >> guessed_number)) {
            std::cout << "Invalid data! Try again." << std::endl;
            return -1;
        }

        if (guessed_number < secret_number) {
            std::cout << "The secret number is larger!\n" << std::endl;
        }
        else if (guessed_number > secret_number) {
            std::cout << "The secret number is smaller!\n" << std::endl;
        }
    }
    while (guessed_number != secret_number);

    std::cout << "You found the secret number!" << std::endl;

    return 0;
}
```
