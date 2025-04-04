#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include <string>
#include "Car.h"
#include "Weather.h"

struct RaceResult {
    Car* car;
    double time;
};

class Circuit {
public:
    Circuit();
    ~Circuit();
    
    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
    
private:
    double circuitLength;
    Weather raceWeather;
    std::vector<Car*> cars;
    std::vector<RaceResult> results;
    
    void CleanUp();
};

#endif