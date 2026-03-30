#include "Fiat.h"

double Fiat::GetFuelCapacity() const{
    return 40.0;
}

double Fiat::GetFuelConsumption() const{
    return 4.5;
}

double Fiat::GetAverageSpeed(Weather weather) const{
    if(weather==Weather::Rain) return 60.0;
    if(weather==Weather::Sunny) return 80.0;
    return 40.0;
}

std::string Fiat::GetName() const{
    return "Fiat";
}