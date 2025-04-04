#ifndef BMW_H
#define BMW_H

#include "Car.h"

class BMW : public Car {
public:
    BMW();
    virtual ~BMW() {}
    
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