#ifndef VEHICLE_H
#define VEHICLE_H

#include "VehicleType.h"
#include <ostream>

struct Vehicle {
    const VehicleType type;
    const float starting_cost;
    const float price_per_km;

    friend std::ostream& operator <<(std::ostream& os, const Vehicle& other)
    {
        switch (other.type) {
            case VehicleType::taxi:
                os << "Taxi";
        }

        return os;
    }
};

#endif