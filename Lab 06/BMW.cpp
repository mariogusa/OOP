#include "BMW.h"

BMW::BMW() 
    : fuelCapacity(55.0), fuelConsumption(0.18), speedSunny(130.0), speedRain(110.0), speedSnow(90.0)
{}

double BMW::race(double circuitLength, Weather weather) {
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

std::string BMW::getName() const {
    return "BMW";
}