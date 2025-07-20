#include "Magnet.h"
#include <iostream>

Magnet::Magnet(const std::string& name, double strength)
    : Device(name), field_strength_(strength) {}

void Magnet::setFieldStrength(double strength) {
    field_strength_ = strength;
    std::cout << name_ << " field set to " << field_strength_ << " Tesla.\n";
}

double Magnet::getFieldStrength() const { return field_strength_; }

void Magnet::simulate(TemperatureSensor& sensor) {
    if (status_) {
        double heat_generated = field_strength_ * 0.1;  // arbitrary heat factor
        sensor.increaseTemperature(heat_generated);

        std::cout << name_ << " running at " << field_strength_ << " Tesla, generating heat: "
                  << heat_generated << " °C\n";
    } else {
        std::cout << name_ << " is OFF.\n";
    }
}
