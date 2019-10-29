#include "Car.h"
#include <iostream>
#include <iomanip>
#include <utility>

Car::Car(const std::string car_make, const float tank_size, const float fuel_consumption)
    : car_make_{std::move(car_make)}
    , tank_size_{tank_size}
    , fuel_consumption_{fuel_consumption}
    , fuel_{tank_size}
{
}

void Car::drive(const float driving_distance)
{
    const float fuel_required = calculate_fuel_consumption(driving_distance);
    const float fuel_left_after_driving = fuel_ - fuel_required;

    if (fuel_left_after_driving >= 0.0f) {
        fuel_ = fuel_left_after_driving;
        trip_meter_ += driving_distance;

        std::cout << std::fixed << std::setprecision(2) << car_make_ << " - " << fuel_ 
                  << " litres left - " << trip_meter_ << " km driven.\n";
    }
    else {
        std::cout << "Too little fuel for the driving distance.\n";
    }
}

void Car::fill_the_tank()
{
    const float fuel_missing = tank_size_ - fuel_;

    if (fuel_missing <= 0) {
        return;
    }

    fuel_ = tank_size_;

    const float filling_tank_cost = calculate_fuel_cost(fuel_missing);

    std::cout << std::fixed << std::setprecision(2) << car_make_ << " - Filled the tank. Costs " 
              << filling_tank_cost << " € for " << fuel_missing << " litres.\n";
}

float Car::calculate_fuel_consumption(const float driving_distance) const
{
    return (fuel_consumption_ / 100.0) * driving_distance;
}

float Car::calculate_fuel_cost(const float fuel) const
{
    return fuel * fuel_price_per_litre;
}