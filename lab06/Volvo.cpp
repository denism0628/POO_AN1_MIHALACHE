#include "Volvo.h"

double Volvo::GetFuelCapacity() const{
    return 60.0;
}

double Volvo::GetFuelConsumption() const{
    return 9.0;
}

double Volvo::GetAverageSpeed(Weather weather) const{
    if(weather==Weather::Rain) return 90.0;
    if(weather==Weather::Sunny) return 130.0;
    return 80.0;
}

std::string Volvo::GetName() const{
    return "Volvo";
}