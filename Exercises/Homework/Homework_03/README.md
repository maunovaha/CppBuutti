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

> ... 

```cpp
```

## Exercise 4 (extra)

> ... 

```cpp
```

## Exercise 5 (extra)

> ... 

```cpp
```

## Exercise 6 (extra)

> ... 

```cpp
```

## Exercise 7 (extra)

> ... 

```cpp
```