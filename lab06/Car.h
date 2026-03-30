#pragma once
#include "Weather.h"
#include <string>
class Car
{
    public:
    virtual ~Car()=default;
    virtual double GetFuelCapacity() const =0;
    virtual double GetFuelConsumption() const =0;
    virtual double GetAverageSpeed(Weather weather) const=0;
    virtual std::string GetName() const=0;
};

