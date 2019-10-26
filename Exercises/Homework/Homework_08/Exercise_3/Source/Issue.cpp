#include "Issue.h"
#include <utility>

Issue::Issue(const std::string name, const std::string description, const PriorityLevel priority_level)
    : name_{std::move(name)}
    , description_{std::move(description)}
    , priority_level_{priority_level}
{
}

std::ostream& operator <<(std::ostream& os, const Issue& other)
{
    os << other.name_ << " - " << other.description_ << " - ";

    switch (other.priority_level_) {
        case PriorityLevel::high:
            os << "[HIGH PRIORITY]";
            break;
        case PriorityLevel::medium:
            os << "[Medium priority]";
            break;
        case PriorityLevel::low:
            os << "[Low priority]";
            break;
        default:
            os << "[Unknown priority level]";
    }

    return os;
}
