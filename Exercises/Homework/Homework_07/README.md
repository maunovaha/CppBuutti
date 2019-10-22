# Homework 7

## Exercise 1

> Get a *string* input. Make a function that capitalizes the first letter using *std::toupper()* and returns the *string*. Print the *string* in the *main*.
>
> Example output =>  
> *Say a word to capitalize:*  
> *finland*  
> *Finland*  

```cpp
#include <iostream>
#include <string>

std::string capitalize(const std::string& word)
{
    if (word.empty()) {
        return word;
    }

    std::string capitalized_word = word;
    capitalized_word.at(0) = std::toupper(word.at(0));

    return capitalized_word;
}

int main()
{
    std::cout << "Say a word to capitalize:" << std::endl;

    std::string word;
    std::cin >> word;

    std::cout << capitalize(word) << std::endl;

    return 0;
}
```

## Exercise 2

> Find the amount of times you need to multiply *2* by itself so that it the result will be over one billion using a while loop _2*2*2*2*2... > 1 000 000 000_ or *2 n > 1 000 000 000*.

```cpp
#include <iostream>

int main()
{   
    const int billion = 1000000000;

    int times{};
    int n = 2;

    while (n < billion) {
        n *= 2;
        ++times;
    }

    std::cout << "Multiplied 2 by itself " << times << " times." << std::endl;

    return 0;
}
```

**Output**

```
Multiplied 2 by itself 29 times.
```

## Exercise 3

> Create a *Person struct* with *first_name*, *last_name* and *age*. Fill this with your own input. Make a function inside the struct that prints all the data of the user if the creation of the person was successful. If you input *age* below *zero* or as a number over *130* print a message telling the user that their age is invalid.
>
> Example output =>  
> *What is the first name?*  
> *Mikko*  
> *And last name?*  
> *Mallikas*  
> *And age?*  
> *-4*  
> *That is not a valid age!*  
> *What is the first name?*  
> *Mikko*  
> *And last name?*  
> *Mallikas*  
> *And age?*  
> *93*  
> *--- Mikko Mallikas, age 93 ---*

The solution can be found [here](Exercise_3/).

## Exercise 4

> Make a *vector* filled with *strings*. Get int as input and using the *vector.at()* function get the element based on the input integer. Catch the *std::out_of_range* error that you get if you input a too large number and print an error message.

```cpp
```

## Exercise 5

> Take *2* floating numbers as input *a* and *b*. Make a function *divide* that divides *a / b*. Check in this function that *b is not zero*. If *b* is zero throw a *std::string* with text *"Zero division error"*. Catch your error in *main* and print the thrown string *"Zero division error"*.

```cpp
```

## Exercise 6

> Write *1000* times in a file *"I will not automate my homework again"*. ;)

```cpp
```

## Exercise 7

> Read the top *1000* words from a file into your program... Shuffle them using algorithm we learned last week and replace the file with the words in the new random order. Every time you run this program you should get a new random word.

```cpp
```

