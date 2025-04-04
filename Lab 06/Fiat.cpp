#include "Fiat.h"

Fiat::Fiat() 
    : fuelCapacity(45.0), fuelConsumption(0.15), speedSunny(100.0), speedRain(80.0), speedSnow(60.0)
{}

double Fiat::race(double circuitLength, Weather weather) {
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

std::string Fiat::getName() const {
    return "Fiat";
}