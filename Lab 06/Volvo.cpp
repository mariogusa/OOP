#include "Volvo.h"

Volvo::Volvo() 
    : fuelCapacity(60.0), fuelConsumption(0.2), speedSunny(120.0), speedRain(100.0), speedSnow(80.0)
{}

double Volvo::race(double circuitLength, Weather weather) {
    double fuelNeeded = circuitLength * fuelConsumption;
    if (fuelNeeded > fuelCapacity)
        return -1;
    
    double speed = 0.0;
    switch(weather) {
        case Weather::Sunny: speed = speedSunny; break;
        case Weather::Rain:  speed = speedRain; break;
        case Weather::Snow:  speed = speedSnow; break;
    }
    return circuitLength / speed;
}

std::string Volvo::getName() const {
    return "Volvo";
}