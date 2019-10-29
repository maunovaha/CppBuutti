#include "FillTankCommand.h"
#include <stdexcept>

bool FillTankCommand::execute(Car& car, const std::vector<std::string>& args) const
{
    car.fill_the_tank();

    return true;
}
