#include "Seat.h"

Seat::Seat() 
    : fuelCapacity(50.0), fuelConsumption(0.16), speedSunny(110.0), speedRain(90.0), speedSnow(70.0)
{}

double Seat::race(double circuitLength, Weather weather) {
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

std::string Seat::getName() const {
    return "Seat";
}