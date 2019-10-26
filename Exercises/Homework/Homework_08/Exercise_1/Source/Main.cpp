#include "TripRecorder.h"
#include "VehicleFactory.h"
#include "TaxiPolicy.h"

int main()
{
    const Company company{"Buutti Oy", TaxiPolicy{3.0f, -15.0f}};
    const TripRecorder trip_recorder{company, VehicleFactory::taxi()};

    return 0;
}