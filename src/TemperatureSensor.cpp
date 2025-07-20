#include "TemperatureSensor.h"
#include <iostream>
#include <chrono>

TemperatureSensor::TemperatureSensor(const std::string& name, double initial_temp)
    : Device(name), temperature_(initial_temp),
      distribution_(0.0, 0.05) // Smaller natural fluctuations
{
    generator_.seed(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
}

double TemperatureSensor::readTemperature() const {
    return temperature_;
}

void TemperatureSensor::increaseTemperature(double delta) {
    temperature_ += delta;
}

void TemperatureSensor::simulate() {
    if (status_) {
        // Natural small fluctuations
        temperature_ += distribution_(generator_);
        // Natural cooling over time
        temperature_ -= 0.03;  // cooling rate
        std::cout << name_ << " reading: " 
                  << temperature_ << " °C\n";
    } else {
        std::cout << name_ << " is OFF, no data available.\n";
    }
}
