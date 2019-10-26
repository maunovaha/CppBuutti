#ifndef TRIP_H
#define TRIP_H

#include "Vehicle.h"

class TaxiPolicy; // Fixes circular dependency
class Trip {
public:
    Trip(const Vehicle& vehicle, float distance, const float temperature);
    float cost() const;

    friend TaxiPolicy;
private:
    const Vehicle vehicle_;
    const float distance_;
    const float temperature_;
};

#endif