# Homework 4

## Exercise 1

> We need a program for our club and you are tasked to create the data structures for it.
>
> Create a *Date struct* with *day*, *month* and *year*.
>
> Create also a *Person struct* that uses the *Date struct* and has the following properties: *name, birthdate, gender, occupation, registration_date* and if the *Person* is an *active_member* or not.
>
> Choose fitting data types for the fields and create a print function that prints all data in a format of your choosing.

The solution can be found [here](Exercise_1/).

**Output**

```
==============================
Name: John Jackson
Gender: Male
Occupation: Artist
Birthdate: 1.1.1987
Registration date: 11.12.2000
Active member: false
==============================

==============================
Name: Mickey Mouse
Gender: Male
Occupation: Detective
Birthdate: 3.4.1977
Registration date: 7.2.2011
Active member: true
==============================

==============================
Name: Emma Kidman
Gender: Female
Occupation: Singer
Birthdate: 1.1.1960
Registration date: 6.5.1978
Active member: true
==============================
```

## Exercise 2

> Create a function that has a *static counter* inside which counts how many times the function has been called, and prints the value of it.
>
> Example output =>  
> *The method Person::debug() has been called 1 time(s).*  
> *The method Person::debug() has been called 2 time(s).*  
> *The method Person::debug() has been called 3 time(s).*  
> *The method Person::debug() has been called 4 time(s).*
>
> Also add an *id* field for the *Person struct* (from the last assignment) that starts from *1* and increments by one for every new person created *2, 3, 4, 5...* and so forth. Use *static* to keep track of how many persons have been created to give everyone a unique *id*.

The solution can be found [here](Exercise_2/).

**Output**

```
Created a person with id: 1
Created a person with id: 2
Created a person with id: 3
The method Person::debug() has been called 1 time(s).
The method Person::debug() has been called 2 time(s).
The method Person::debug() has been called 3 time(s).
The method Person::debug() has been called 4 time(s).
Current Person::id value is: 3
```

## Exercise 3

> Create a *Vector struct*.
>
> The *Vector* should have *4* properties. Its *origin (x, y)*, and its *direction (x, y)*. 
>
> Create a function inside the struct that prints the data of the vector in the following format: *Vector, origin {x, y}, direction {x, y}*.

The solution can be found [here](Exercise_3/).

**Output**

```
Vector, origin {1, 2}, direction {3, 4}
Vector, origin {5, 6}, direction {7, 8}
```

## Exercise 4

> Create a function that takes two vectors and returns *true* if they are *perpendicular* and *false* if they are not.
>
> - *Perpendicular* means that the *angle between the vectors is 90 degrees.*
>
> - Vectors are *perpendicular* if their *dot product is 0*.
>
> - *Dot product* is calculated using the directions of the vectors and for vectors *{x1, y1}* and *{x2, y2}* it is _x1 * x2 + y1 * y2_.

The solution can be found [here](Exercise_4/).

**Output**

```
Vector, origin {0, 0}, direction {0, 5}
Vector, origin {0, 0}, direction {5, 0}
Vectors are perpendicular!

Vector, origin {0, 0}, direction {2, 5}
Vector, origin {0, 0}, direction {10, -4}
Vectors are perpendicular!

Vector, origin {0, 0}, direction {22, 65}
Vector, origin {0, 0}, direction {60, 25}
Vectors are not perpendicular!
```

## Exercise 5

> Create a new struct called *Point* that has *x* and *y* properties. Then replace the *origin* and *direction* fields of the previously used *Vector struct* with the new *Point struct*.
>
> After this, create a function *end_point* inside the *Vector struct* that returns the point where the vector ends.

The solution can be found [here](Exercise_5/).

**Output**

```
Vector, origin {-1, -1}, direction {3, 4}
The vector end point is: {2, 3}
```

## Exercise 6

> ...

```cpp
```

## Exercise 7

> ... TODO (later on) ...

```cpp
```