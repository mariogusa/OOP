#ifndef FIAT_H
#define FIAT_H

#include "Car.h"

class Fiat : public Car {
public:
    Fiat();
    virtual ~Fiat() {}
    
    virtual double race(double circuitLength, Weather weather) override;
    virtual std::string getName() const override;
    
private:
    double fuelCapacity;
    double fuelConsumption;
    double speedSunny;
    double speedRain;
    double speedSnow;
};

#endif