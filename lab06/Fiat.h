#pragma once
#include "Car.h"

class Fiat: public Car
{
    public:
        double GetFuelCapacity() const override;
        double GetFuelConsumption() const override;
        double GetAverageSpeed(Weather weather) const override;
        std::string GetName() const override;
};