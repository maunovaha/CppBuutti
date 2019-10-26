#include "TaxiPolicy.h"

TaxiPolicy::TaxiPolicy(const float min_distance, const float min_temperature)
    : min_distance_{min_distance}, min_temperature_{min_temperature}
{
}

bool TaxiPolicy::allows_trip(const Trip& trip) const
{
    return trip.distance_ > min_distance_ || trip.temperature_ < min_temperature_;
}