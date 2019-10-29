#include "CarCommander.h"
#include "CarFactory.h"
#include "DriveCommand.h"
#include "FillTankCommand.h"

int main()
{   
    const std::unordered_map<std::string, Car> cars = {
        {"Volkswagen", CarFactory::volkswagen()},
        {"Peugeot",    CarFactory::peugeot()},
        {"Toyota",     CarFactory::toyota()}
    };

    DriveCommand drive_command;
    FillTankCommand fill_tank_command;

    const std::unordered_map<std::string, CarCommand*> commands = {
        {"./drive", &drive_command},
        {"./fill_tank", &fill_tank_command}
    };

    const CarCommander car_commander{cars, commands};

    return 0;
}
