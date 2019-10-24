# Homework 8

## Exercise 1

> A company has a rule which allows employees to use a taxi if a work related journey is over *3* kilometers or it's under *-15* celsius. Make a function that returns if person is allowed to use a taxi that takes in *float distance* and *float temperature*. Make also inputs to get in data.
>
> If Taxi journey is allowed, make another function to calculate how much it will cost. Taxi in Oulu costs *5€ + 1.80€/km*.
>
> Example output =>  
> *Journey length in km?*  
> *2*  
> *Temperature in Celsius?*  
> *20*  
> *You are not allowed to drive Taxi!*
>
> *Journey length in km?*  
> *8*  
> *Temperature in Celsius?*  
> *20*  
> *You can use a Taxi!*  
> *Taxi costs 19.40€*
>
> *Journey length in km?*  
> *2*  
> *Temperature in Celsius?*  
> *-25*  
> *You can use a Taxi!*  
> *Taxi costs 8.60€*

```cpp
```

## Exercise 2

> In last homework, we made a *Person struct*. Make a *Person class* instead that works in the same way.

```cpp
```

## Exercise 3

> Make a *class* called *Issue* that has *name*, *description* and *priority_level* (enum). The priority level should have *high*, *medium* and *low* as enum values.
>
> Make a function for the *Issue class* that prints it.
>
> Example output =>  
> *Fire! - The building is on fire - HIGH PRIORITY!*  
> *Trash can - It smelss and should be changed - Medium priority.*  
> *Buy new curtains - The old curtains are ugly - Low priority.*

```cpp
```

## Exercise 4

> Continue the *Vector2 class* we made at the lecture and overload the *<< operator* to easily use *std::cout* to print our point values.
>
> By doing this, e.g. ```cpp std::cout << my_point << std::endl;``` should print somethung like ```{x, y}```.

```cpp
```

## Exercise 5

> Let's make an app for a courier company that owns multiple cars. One *Volkswagen*, one *Peugeot* and one *Toyota*. Make a *Car class* to handle all the cars that can be constructed using the *make*, *tank_size*, and *fuel_consumption*.
>
> Below is the list of cars that you need to construct.
>
> | Make         | Tank size     | Fuel consumption     |  
> | ------------ | ------------- | -------------------- |  
> | Volkswagen   | 50 litres     | 5.2 litres / 100 km  |  
> | Peugeot      | 53 litres     | 4.6 litres / 100 km  |  
> | Toyota       | 44 litres     | 6.6 litres / 100 km  |
>
> Have two functions for a *Car class*. A function called *drive(...)*  that takes in the *kilometer* as a parameter; Reduces the right amount of *fuel*, and if you are about to run out of *fuel*, it should print *"Too little fuel"* instead. If there is enough *fuel*, it tells the user how much *fuel* is left. You can also make a *trip_meter* variable that counts how much the car has driven in total.
>
> The other function is *pump_gas()* which fills the tank to it's brim, and tells the user how much it cost. One liter of *fuel* costs *1.50€*.
>
> Save these cars in an *unordered_map* so that you can get them from user input. You need to also parse the input from the command line.
>
> Example output =>  
> *Type the car make and operation (e.g. `Toyota drive 30km`):*  
> *Toyota drive 30km*  
> *Toyota - 53.02 litres left - 30km driven*  
> *Toyota drive 700km*  
> *Toyota - 6.82 litres left - 730km driven*  
> *Toyota drive 250km*  
> *Can't! Not enough fuel!*  
> *Toyota fill*  
> *Toyota - Filled tank. Costs 72.27€ for 48.18 litres.*  
> *Toyota drive 250km*  
> *Toyota - 38.5 litres left - 980km driven*

```cpp
```