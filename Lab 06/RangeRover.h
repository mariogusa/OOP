#ifndef RANGEROVER_H
#define RANGEROVER_H

#include "Car.h"

class RangeRover : public Car {
public:
    RangeRover();
    virtual ~RangeRover() {}
    
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