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
    capitalized_word.first() = std::toupper(word.first());

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

> Make a *vector* filled with *strings*. Get *int* as input and using the *vector.at()* function get the element based on the input integer. Catch the *std::out_of_range* error that you get if you input a too large number and print an error message.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>

void reset()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int read_int()
{
    int value{};
    const bool success = static_cast<bool>(std::cin >> value);

    reset();

    if (!success) {
        std::cerr << "Invalid value. Try again." << std::endl;
        return read_int();
    }

    return value;
}

int main()
{
    const std::vector<std::string> names = {"Mauno", "Pekka", "Bazi"};

    std::cout << "Give a slot number: " << std::endl;
    const int slot = read_int();

    try {
        const std::string name = names.at(slot);
        std::cout << "The name at slot " << slot << " is " << name << std::endl;
    } 
    catch (const std::out_of_range& e) {
        std::cerr << "The given slot " << slot << " is outside the range of names (last slot: " 
                  << (names.size() - 1) << ")" << std::endl;
        return -1;
    }

    return 0;
}
```

## Exercise 5

> Take *2* floating numbers as input *a* and *b*. Make a function *divide* that divides *a / b*. Check in this function that *b is not zero*. If *b* is zero throw a *std::string* with text *"Zero division error"*. Catch your error in *main* and print the thrown string *"Zero division error"*.

```cpp
#include <iostream>
#include <stdexcept>

void reset()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

float read_float()
{
    float value{};
    const bool success = static_cast<bool>(std::cin >> value);

    reset();

    if (!success) {
        std::cerr << "Invalid value. Try again." << std::endl;
        return read_float();
    }

    return value;
}

float divide(const float a, const float b)
{
    if (b == 0.0f) {
        // We could throw std::string here, but it's bad practice, so using
        // std::invalid_argument instead.
        // 
        // See: https://stackoverflow.com/questions/134569/c-exception-throwing-stdstring
        throw std::invalid_argument("Zero division error");
    }

    return a / b;
}

int main()
{
    std::cout << "Give the value for number (a):" << std::endl;
    const float a = read_float();

    std::cout << "Give the value for number (b):" << std::endl;
    const float b = read_float();

    try {
        const float result = divide(a, b);

        std::cout << "Number " << a << " divided by " << b << " is " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
```

## Exercise 6

> Write *1000* times in a file *"I will not automate my homework again"*. ;)

```cpp
#include <iostream>
#include <string>
#include <fstream>

class FileWriter {
public:
    static void write(const std::string& file_name, const std::string& text, const int times = 1);
};

void FileWriter::write(const std::string& file_name, const std::string& text, const int times)
{
    std::fstream file_stream;
    file_stream.open(file_name, file_stream.trunc | file_stream.out);

    if (!file_stream.is_open()) {
        throw std::runtime_error("Cannot open " + file_name + " for writing!");
    }

    for (int i = 0; i < times; ++i) {
        file_stream << text << "\n";
    }
}

int main()
{
    FileWriter::write("confession.txt", "I will not automate my homework again.", 1000);

    return 0;
}
```

## Exercise 7 _**(todo later on...)**_

> Read the top *1000* words from a [file](https://www.ef.com/ca/english-resources/english-vocabulary/top-1000-words/) into your program. Shuffle them using algorithm we learned last week and replace the file with the words in the new random order. Every time you run this program you should get a new random word.

## Exercise 8 _**(todo later on...)**_

> When you get input for the national identification number throw an error if it isn't a valid identification number. You can see the rules for the valid identification numbers from [here](https://en.wikipedia.org/wiki/National_identification_number#Finland) and [here](https://fi.wikipedia.org/wiki/Henkilötunnus).

## Exercise 9

> Go to Project Gutenberg. Open [e-book library](https://www.gutenberg.org/browse/scores/top) and download a book of your choice.
>
> Read the file and using an *unordered_map* count all the words in the entire text. Print out the top *20* most used words in the text. Remember to catch errors if the file doesn't exist.

The solution can be found [here](Exercise_9/).

**Output**

```
===============================================
Top 20 most used words in the book
===============================================
"the" appears 7984 times.
"and" appears 5754 times.
"to" appears 4504 times.
"i" appears 4499 times.
"of" appears 3710 times.
"a" appears 2933 times.
"he" appears 2509 times.
"in" appears 2475 times.
"that" appears 2365 times.
"was" appears 1804 times.
"it" appears 1736 times.
"as" appears 1561 times.
"we" appears 1493 times.
"for" appears 1488 times.
"is" appears 1456 times.
"his" appears 1445 times.
"not" appears 1314 times.
"with" appears 1306 times.
"my" appears 1213 times.
"you" appears 1197 times.
"at" appears 1082 times.
"have" appears 1049 times.
```

## Exercise 10 _**(todo later on...)**_

> Continue previous example, but make a file writer of your own design where the program saves all the people. You can use one line per person for example.
>
> When you open the app again it should read in all the people. You should also be able to delete people and if you have time edit people (if they change their last name, for example). If you don't get any ideas on how to save the data look at *.csv files* that work also on excel / openoffice calc.
