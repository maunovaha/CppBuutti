#include "TripRecorder.h"
#include "InputReader.h"
#include <iostream>
#include <iomanip>

TripRecorder::TripRecorder(const Company& company, const Vehicle& vehicle) 
    : company_{company}, vehicle_{vehicle}
{
    std::cout << "==========================================\n"
              << "Started to record " << vehicle << " trips for " << company_
              << "\n==========================================\n";

    record();
}

void TripRecorder::record()
{
    display_trip_count();

    std::cout << "What is the next trip length in km?\n";
    const float trip_length = InputReader::read_min<float>(1, "Invalid trip length. Try again.");

    std::cout << "How about the temperature in Celcius?\n";
    const float temperature = InputReader::read<float>("Invalid temperature. Try again.");

    const Trip trip{vehicle_, trip_length, temperature};

    if (company_.allows_trip(trip)) {
        std::cout << std::fixed << std::setprecision(2)
                  << "You can use " << vehicle_ << "!\n" << vehicle_ << " costs " << trip.cost()
                  << "€" << std::endl;

        add_trip(trip);
    }
    else {
        std::cout << "You are not allowed to use " << vehicle_ << "!" << std::endl;
    }

    record();
}

void TripRecorder::add_trip(const Trip& trip)
{
    trips_.emplace_back(trip);
}

void TripRecorder::display_trip_count() const
{
    std::cout << "\n-------------------------------------------------\n"
              << "The people of the company have recorded " << trip_count() << " trips."
              << "\n-------------------------------------------------\n\n";
}

int TripRecorder::trip_count() const
{
    return trips_.size();
}