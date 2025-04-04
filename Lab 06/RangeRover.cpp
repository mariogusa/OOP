#include "RangeRover.h"

RangeRover::RangeRover() 
    : fuelCapacity(80.0), fuelConsumption(0.25), speedSunny(140.0), speedRain(120.0), speedSnow(100.0)
{}

double RangeRover::race(double circuitLength, Weather weather) {
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

std::string RangeRover::getName() const {
    return "RangeRover";
}