#ifndef MAGNET_H
#define MAGNET_H

#include "Device.h"
#include "TemperatureSensor.h"

class Magnet : public Device {
    double field_strength_; // Tesla
public:
    Magnet(const std::string& name, double strength = 0.0);

    void setFieldStrength(double strength);
    double getFieldStrength() const;

    void simulate(TemperatureSensor& sensor);
    void simulate() override {} // Optional empty if unused directly
};

#endif
