#ifndef CAR_COMMANDER_H
#define CAR_COMMANDER_H

#include "Car.h"
#include "CarCommand.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>

using CommandParams = std::tuple<std::string, std::string, std::vector<std::string>>;

class CarCommander {
public:
    CarCommander(const std::unordered_map<std::string, Car>& cars, 
                 const std::unordered_map<std::string, CarCommand*>& car_commands);
private:
    void loop();
    CommandParams split_user_command_to_params(const std::string& user_command) const;
    std::string value_or_empty(const std::vector<std::string>& container, const int index) const;
    bool is_valid_command_name(const std::string& command_name) const;
    bool is_valid_car_make(const std::string& car_make) const;
    
    std::unordered_map<std::string, Car> cars_;
    const std::unordered_map<std::string, CarCommand*> car_commands_;
};

#endif