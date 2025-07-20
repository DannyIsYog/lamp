#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Device.h"
#include <random>

class TemperatureSensor : public Device {
    double temperature_;
    std::default_random_engine generator_;
    std::normal_distribution<double> distribution_;

public:
    TemperatureSensor(const std::string& name, double initial_temp = 25.0);

    double readTemperature() const;
    void increaseTemperature(double delta);
    void simulate() override;
};

#endif
