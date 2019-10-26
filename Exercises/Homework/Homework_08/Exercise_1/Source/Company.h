#ifndef COMPANY_H
#define COMPANY_H

#include "Trip.h"
#include "TaxiPolicy.h"
#include <string>
#include <ostream>

class Company {
public:
    Company(const std::string name, const TaxiPolicy& taxi_policy);
    bool allows_trip(const Trip& trip) const;

    friend std::ostream& operator <<(std::ostream& os, const Company& other);
private:
    const std::string name_;
    const TaxiPolicy taxi_policy_;
};

#endif