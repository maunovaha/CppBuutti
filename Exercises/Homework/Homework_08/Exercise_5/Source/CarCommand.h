#ifndef CAR_COMMAND_H
#define CAR_COMMAND_H

#include "Car.h"
#include <vector>

class CarCommand {
public:
    virtual bool execute(Car& car, const std::vector<std::string>& args) const = 0;
    virtual ~CarCommand() = default;
};

#endif