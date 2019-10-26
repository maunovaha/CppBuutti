#ifndef TRIP_RECORDER_H
#define TRIP_RECORDER_H

#include "Trip.h"
#include "Company.h"
#include <vector>

class TripRecorder {
public:
    TripRecorder(const Company& company, const Vehicle& vehicle);
private:
    void record();
    void add_trip(const Trip& trip);
    void display_trip_count() const;
    int trip_count() const;
    
    const Company company_;
    const Vehicle vehicle_;
    std::vector<Trip> trips_;
};

#endif