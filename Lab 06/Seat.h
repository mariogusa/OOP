#ifndef SEAT_H
#define SEAT_H

#include "Car.h"

class Seat : public Car {
public:
    Seat();
    virtual ~Seat() {}
    
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