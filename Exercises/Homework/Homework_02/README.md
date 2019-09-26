# Homework 2

## Exercise 1

> Create a function that calculates the speed of an object in km/h when it is given distance it moved in meters and time in seconds. Note: *1 m/s is 3.6 km/h*.
> 
> Example output =>  
> *What is the distance that the object moved in meters?*  
> *8*  
> *How many seconds did it take?*  
> *2*  
> *Your speed is 14.4000 km/h*

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
> **_c)_** It is beach day if the sun is shining, it is not raining and the temperatur is 20 degress celcius or above.
> **_d)_** Johnny is happy if he has a date either with Cindy or with Mindy on Tuesday night. However, having a date with two girls at the same time causes obvious trouble. Also, staying alone makes Johnny sad.

```cpp
...
```

## Exercise 3

> Make an application that prints the price of admission to a swimming pool. The application should ask your age and if you are a student. Create a *single* if expression that checks if you are eligible for a discount.
> 
> The pricing table currently looks like this:
> 
> | Tables        | Are           | Cool  |  
> | ------------- |:-------------:| -----:|  
> | col 3 is      | right-aligned | $1600 |  
> | col 2 is      | centered      |   $12 |  
> | zebra stripes | are neat      |    $1 |

```cpp
...
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
> *What operand you want to use? (+, -, *, /)*  
> *+*  
> *The answer is 11.*

```cpp
...
```

## Exercise 5

> Make a guessing game where the user has to guesss a secret number of your choice.
> 
> **Phase 1:** Make it say if the number is smaller, larger or correct.
> 
> Example output =>
> *Guess a number?*  
> *15*  
> *The secret number is larger!*
>
> *Guess a number?*  
> *42*  
> *You found the secret number!*
>
> **Phase 2:** Make it repeat until you find the right answer. *(Tip: You can make a function repeat by calling it in the end of it.)*
>
> **Phase 3:** Use a random number generator to generate the secret number from *0* to *100*. Read the (following theory)[http://www.fredosaurus.com/notes-cpp/misc/random.html] on random number generation. *(Tip: Don't make the random number generation repeat!)*

```cpp
...
```