#include "BMW.h"

double BMW::GetFuelCapacity() const{
    return 65.0;
}

double BMW::GetFuelConsumption() const{
    return 10.0;
}

double BMW::GetAverageSpeed(Weather weather) const{
    if(weather==Weather::Rain) return 110.0;
    if(weather==Weather::Sunny) return 130.0;
    return 95.0;
}

std::string BMW::GetName() const{
    return "BMW";
}