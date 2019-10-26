#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include "Vehicle.h"

class VehicleFactory {
public:
    VehicleFactory() = delete;
    static Vehicle taxi();
};

#endif