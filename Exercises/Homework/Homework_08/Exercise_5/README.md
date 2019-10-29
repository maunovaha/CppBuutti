# Exercise 5

> Let's make an app for a courier company that owns multiple cars. One *Volkswagen*, one *Peugeot* and one *Toyota*. Make a *Car class* to handle all the cars that can be constructed using the *car_make*, *tank_size*, and *fuel_consumption*.
>
> Below is the list of cars that you need to construct.
>
> | Car make     | Tank size     | Fuel consumption     |  
> | ------------ | ------------- | -------------------- |  
> | Volkswagen   | 50 litres     | 5.2 litres / 100 km  |  
> | Peugeot      | 53 litres     | 4.6 litres / 100 km  |  
> | Toyota       | 44 litres     | 6.6 litres / 100 km  |
>
> Have two functions for a *Car class*. A function called *drive(...)*  that takes in the *driving_distance* as a parameter; Reduces the right amount of *fuel*, and if you are about to run out of *fuel*, it should print *"Too little fuel for the driving distance."* instead. If there is enough *fuel*, it tells the user how much *fuel* is left. You can also make a *trip_meter* variable that counts how much the car has driven in total.
>
> The other function is *fill_the_tank()* which fills the tank to it's brim, and tells the user how much it cost. One liter of *fuel* costs *1.50€*.
>
> Save these cars in an *unordered_map* so that you can get them from user input. You need to also parse the input from the command line.
>
> Example output =>  
> *Type the car make and operation (e.g. "./drive Toyota 30 km"):*  
> *./drive Toyota 30 km*  
> *Toyota - 53.02 litres left - 30 km driven.*
>
> *Type the car make and operation (e.g. "./drive Toyota 30 km"):*  
> *./drive Toyota 700 km*  
> *Toyota - 6.82 litres left - 730 km driven.*
>
> *Type the car make and operation (e.g. "./drive Toyota 30 km"):*  
> *./drive Toyota 250 km*  
> *Too little fuel for the driving distance.*
>
> *Type the car make and operation (e.g. "./drive Toyota 30 km"):*  
> *./fill_tank Toyota*  
> *Toyota - Filled the tank. Costs 72.27€ for 48.18 litres.*
>
> *Type the car make and operation (e.g. "./drive Toyota 30 km"):*  
> *./drive Toyota 250 km*  
> *Toyota - 38.5 litres left - 980 km driven.*

## How to compile

```
g++ Source/Main.cpp Source/CarFactory.cpp Source/Car.cpp Source/CarCommander.cpp Source/DriveCommand.cpp Source/FillTankCommand.cpp Source/InputReader.cpp Source/StringUtil.cpp -std=c++17 -o main
```