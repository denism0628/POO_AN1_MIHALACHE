#include <iostream>

float operator"" _Kelvin(long double k)
{
    return float(k-273.15);
}

float operator"" _Kelvin(unsigned long long k)
{
    return float(k-273.15);
}

float operator"" _Fahrenheit(long double f)
{
    return float((f-32.0)/1.8);
}

float operator"" _Fahrenheit(unsigned long long f)
{
    return float((f-32.0)/1.8);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout<<a<<std::endl;
    std::cout<<b;
    return 0;
}
