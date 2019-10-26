#include "Trip.h"

Trip::Trip(const Vehicle& vehicle, const float distance, const float temperature) 
    : vehicle_{vehicle}, distance_{distance}, temperature_{temperature}
{
}

float Trip::cost() const
{
    return vehicle_.starting_cost + (distance_ * vehicle_.price_per_km);
}