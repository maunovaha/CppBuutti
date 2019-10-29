#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    Car(const std::string car_make, const float tank_size, const float fuel_consumption);
    void drive(const float driving_distance);
    void fill_the_tank();
private:
    float calculate_fuel_consumption(const float driving_distance) const;
    float calculate_fuel_cost(const float fuel) const;

    const std::string car_make_;
    const float tank_size_;
    const float fuel_consumption_;

    float fuel_;
    float trip_meter_ = 0;

    inline static const float fuel_price_per_litre = 1.5f;
};

#endif