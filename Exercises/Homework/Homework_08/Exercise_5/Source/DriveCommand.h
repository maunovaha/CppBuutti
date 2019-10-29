#ifndef DRIVE_COMMAND_H
#define DRIVE_COMMAND_H

#include "CarCommand.h"
#include "Car.h"
#include <string>

class DriveCommand : public CarCommand {
public:
    bool execute(Car& car, const std::vector<std::string>& args) const override;
};

#endif
