#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H

#include "Car.h"

class CarFactory {
public:
    CarFactory() = delete;
    static Car volkswagen();
    static Car peugeot();
    static Car toyota();
};

#endif
