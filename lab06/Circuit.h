#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
    private:
        static const int MAX_CARS=100;
        Car* cars[MAX_CARS];   
        int carCount;
        double length;
        Weather weather;

    struct Result{
        Car* car;
        double time;
        bool finished;
    };
    Result results[MAX_CARS];

    public:
        Circuit();
        ~Circuit();
        void SetLength(double length);
        void SetWeather(Weather weather);
        void AddCar(Car* cars);
        void Race();
        void ShowFinalRanks();
        void ShowWhoDidNotFinish();
};