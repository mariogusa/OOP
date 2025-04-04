#ifndef CAR_H
#define CAR_H

#include <string>
#include "Weather.h"

class Car {
public:
    virtual ~Car() {}
    virtual double race(double circuitLength, Weather weather) = 0;
    
    virtual std::string getName() const = 0;
};

#endif