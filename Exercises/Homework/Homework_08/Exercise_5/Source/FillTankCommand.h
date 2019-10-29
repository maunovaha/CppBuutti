#ifndef FILL_TANK_COMMAND_H
#define FILL_TANK_COMMAND_H

#include "CarCommand.h"
#include "Car.h"
#include <string>

class FillTankCommand : public CarCommand {
public:
    bool execute(Car& car, const std::vector<std::string>& args) const override;
};

#endif
