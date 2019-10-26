#include "VehicleFactory.h"

Vehicle VehicleFactory::taxi()
{
    return {.type = VehicleType::taxi, .starting_cost = 5.0f, .price_per_km = 1.8f};
}
