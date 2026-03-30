#include "Seat.h"

double Seat::GetFuelCapacity() const{
    return 50.0;
}

double Seat::GetFuelConsumption() const{
    return 5.0;
}

double Seat::GetAverageSpeed(Weather weather) const{
    if(weather==Weather::Rain) return 70.0;
    if(weather==Weather::Sunny) return 90.0;
    return 50.0;
}

std::string Seat::GetName() const{
    return "Seat";
}