# Lecture 8

> This lecture discusses about algorithms, tuples and compile-time operations.

## Exercise 1

> We had earlier a homework assignment where a *vector {1, 2, 3, 5}* would turn into following structure:
>
> *a*  
> *aa*  
> *aaa*  
> *aaaaa*  
>
> Now do the same using the *std::accumulate* function.

```cpp
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <utility>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 5};

    auto make_pyramid = [](std::string a, int b)
    {
        return std::move(a) + std::string(b, 'a') + "\n";
    };

    std::string pyramid = std::accumulate(numbers.begin(), numbers.end(), std::string{}, make_pyramid);

    std::cout << pyramid;

    return 0;
}
```

## Exercise 2

> ...

```cpp
```
