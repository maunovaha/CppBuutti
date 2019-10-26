#include "Company.h"
#include <utility>

Company::Company(const std::string name, const TaxiPolicy& taxi_policy) 
    : name_{std::move(name)}, taxi_policy_{taxi_policy}
{
}

bool Company::allows_trip(const Trip& trip) const
{
    return taxi_policy_.allows_trip(trip);
}

std::ostream& operator <<(std::ostream& os, const Company& other)
{
    os << other.name_;
    return os;
}