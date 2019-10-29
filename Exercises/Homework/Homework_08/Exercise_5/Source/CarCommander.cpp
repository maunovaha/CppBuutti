#include "CarCommander.h"
#include "InputReader.h"
#include "StringUtil.h"
#include <iostream>

CarCommander::CarCommander(const std::unordered_map<std::string, Car>& cars, 
                           const std::unordered_map<std::string, CarCommand*>& car_commands) 
    : cars_{cars}
    , car_commands_{car_commands}
{
    loop();
}

void CarCommander::loop()
{
    bool valid_input = false;

    std::cout << "Type the car make and operation (e.g. \"./drive Toyota 30 km\"):\n";

    const std::string user_command = InputReader::read();
    const auto [command_name, car_make, args] = split_user_command_to_params(user_command);

    if (is_valid_command_name(command_name) && is_valid_car_make(car_make)) {
        const CarCommand* car_command = car_commands_.at(command_name);
        Car& target_car = cars_.at(car_make);

        valid_input = car_command->execute(target_car, args);
    }

    if (!valid_input) {
        std::cerr << "Invalid input. Try again.\n";
    } 
    
    loop();
}

CommandParams CarCommander::split_user_command_to_params(const std::string& user_command) const
{
    const std::vector<std::string> params = StringUtil::split(user_command, ' ');
    const std::string command_name = value_or_empty(params, 0);
    const std::string car_make = value_or_empty(params, 1);
    const std::vector<std::string> args = {value_or_empty(params, 2)};

    return {command_name, car_make, args};
}

std::string CarCommander::value_or_empty(const std::vector<std::string>& container, const int index) const
{
    return container.size() > index ? container.at(index) : "";
}

bool CarCommander::is_valid_command_name(const std::string& command_name) const
{   
    return car_commands_.find(command_name) != car_commands_.end();
}

bool CarCommander::is_valid_car_make(const std::string& car_make) const
{
    return cars_.find(car_make) != cars_.end();
}
