#include "Circuit.h"
#include <iostream>
#include <algorithm>

Circuit::Circuit() : circuitLength(0.0), raceWeather(Weather::Sunny) {}

Circuit::~Circuit() {
    CleanUp();
}

void Circuit::SetLength(double length) {
    circuitLength = length;
}

void Circuit::SetWeather(Weather weather) {
    raceWeather = weather;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void Circuit::Race() {
    results.clear();
    for (auto car : cars) {
        double time = car->race(circuitLength, raceWeather);
        results.push_back({ car, time });
    }
}

void Circuit::ShowFinalRanks() const {
    std::vector<RaceResult> finished;
    for (const auto& res : results) {
        if (res.time > 0)
            finished.push_back(res);
    }
    std::sort(finished.begin(), finished.end(), [](const RaceResult& a, const RaceResult& b) {
        return a.time < b.time;
    });
    
    std::cout << "Final Rankings:" << std::endl;
    for (const auto& res : finished) {
        std::cout << res.car->getName() << " finished in " << res.time << " hours." << std::endl;
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    std::cout << "Cars that did not finish:" << std::endl;
    bool any = false;
    for (const auto& res : results) {
        if (res.time < 0) {
            std::cout << res.car->getName() << std::endl;
            any = true;
        }
    }
    if (!any)
        std::cout << "None" << std::endl;
}

void Circuit::CleanUp() {
    for (auto car : cars) {
        delete car;
    }
    cars.clear();
}