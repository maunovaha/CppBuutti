# Exercise 1

> A company has a rule which allows employees to use a taxi if a work related journey is over *3* kilometers or it's under *-15* celsius. Make a function that returns if person is allowed to use a taxi that takes in *float distance* and *float temperature*. Make also inputs to get in data.
>
> If Taxi journey is allowed, make another function to calculate how much it will cost. Taxi in Oulu costs *5€ + 1.80€/km*.
>
> Example output =>  
> \==========================================  
> Started to record Taxi trips for Buutti Oy  
> \==========================================
>
> \-------------------------------------------------  
> The people of the company have recorded 0 trips.  
> \-------------------------------------------------
>
> What is the next trip length in km?  
> 2  
> How about the temperature in Celcius?  
> 20  
> You are not allowed to use Taxi!
>
> \-------------------------------------------------  
> The people of the company have recorded 0 trips.  
> \-------------------------------------------------
>
> What is the next trip length in km?  
> 8  
> How about the temperature in Celcius?  
> 20  
> You can use Taxi!  
> Taxi costs 19.40€  
>
> \-------------------------------------------------  
> The people of the company have recorded 1 trips.  
> \-------------------------------------------------  
>
> What is the next trip length in km?  
> 2  
> How about the temperature in Celcius?  
> -25  
> You can use Taxi!  
> Taxi costs 8.60€
>
> \-------------------------------------------------  
> The people of the company have recorded 2 trips.  
> \-------------------------------------------------

## How to compile

```
g++ Source/Main.cpp Source/TripRecorder.cpp Source/Trip.cpp Source/InputReader.cpp Source/Company.cpp Source/VehicleFactory.cpp Source/TaxiPolicy.cpp -std=c++17 -o main
```
