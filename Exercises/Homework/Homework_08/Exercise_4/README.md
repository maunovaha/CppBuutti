# Exercise 4

> Continue the *Vector2 class* we made at the lecture and overload the *<< operator* to easily use *std::cout* to print our point values.
>
> By doing this, e.g. ```cpp std::cout << my_point << std::endl;``` should print something like ```(x, y)```.

## Program output

```
(1, 2) + (1, 2) = (2, 4)
(1, 2) - (1, 2) = (0, 0)
(1, 2) * 2 = (2, 4)
(1, 2) / 2 = (0.5, 1)
2 * (1, 2) = (2, 4)
```

## How to compile

```
g++ Source/Main.cpp Source/Vector2.cpp -std=c++17 -o main
```