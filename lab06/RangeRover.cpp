#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const{
    return 90.0;
}

double RangeRover::GetFuelConsumption() const{
    return 13.5;
}

double RangeRover::GetAverageSpeed(Weather weather) const{
    if(weather==Weather::Rain) return 100.0;
    if(weather==Weather::Sunny) return 130.0;
    return 90.0;
}

std::string RangeRover::GetName() const{
    return "RangeRover";
}