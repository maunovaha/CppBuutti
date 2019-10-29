#include "DriveCommand.h"
#include <stdexcept>

bool DriveCommand::execute(Car& car, const std::vector<std::string>& args) const
{
    // Not pretty, but should work for now ...
    try {
        const float driving_distance = std::stof(args.at(0));

        if (driving_distance < 0.0f) {
            return false;
        }

        car.drive(driving_distance);
    }
    catch (const std::out_of_range& e) {
        return false;
    }
    catch (const std::invalid_argument& e) {
        return false;
    }

    return true;
}
