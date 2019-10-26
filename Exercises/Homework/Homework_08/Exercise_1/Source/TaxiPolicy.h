#ifndef TAXI_POLICY_H
#define TAXI_POLICY_H

#include "Trip.h"

class TaxiPolicy {
public:
    TaxiPolicy(const float min_distance, const float min_temperature);
    bool allows_trip(const Trip& trip) const;
private:
    const float min_distance_;
    const float min_temperature_;
};

#endif