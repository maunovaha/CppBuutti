#ifndef ISSUE_H
#define ISSUE_H

#include "PriorityLevel.h"
#include <string>
#include <ostream>

class Issue {
public:
    Issue(const std::string name, const std::string description, const PriorityLevel priority_level);

    friend std::ostream& operator <<(std::ostream& os, const Issue& other);
private:
    const std::string name_;
    const std::string description_;
    const PriorityLevel priority_level_;
};

#endif