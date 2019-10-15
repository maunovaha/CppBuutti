# Homework 6

## Exercise 1

> Make a *for loop* that counts all numbers from *1* to *100* but for odd numbers multiplies them by itself instead.

```cpp
#include <iostream>

bool is_odd(const int number)
{
    return number % 2 != 0;
}

int multiply_odd_number(const int number)
{
    return is_odd(number) ? (number * number) : number;
}

int main()
{
    const int min = 1;
    const int max = 100;

    for (int number = min; number <= max; ++number) {
        std::cout << multiply_odd_number(number) << " ";
    }

    return 0;
}
```

**Output**

```
1 2 9 4 25 6 49 8 81 10 121 12 169 14 225 16 289 18 361 20 441 22 529 24 625 26 729 28 841 30 961 32 1089 34 1225 36 1369 38 1521 40 1681 42 1849 44 2025 46 2209 48 2401 50 2601 52 2809 54 3025 56 3249 58 3481 60 3721 62 3969 64 4225 66 4489 68 4761 70 5041 72 5329 74 5625 76 5929 78 6241 80 6561 82 6889 84 7225 86 7569 88 7921 90 8281 92 8649 94 9025 96 9409 98 9801 100
```

## Exercise 2

> ...

```cpp
```

**Output**

```
```

## Exercise 3

> ...

```cpp
```

**Output**

```
```