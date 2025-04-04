#ifndef VOLVO_H
#define VOLVO_H

#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    virtual ~Volvo() {}
    
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