#include "PowerSupply.h"
#include <iostream>

PowerSupply::PowerSupply(const std::string& name, double voltage)
    : Device(name), voltage_(voltage) {}

void PowerSupply::setVoltage(double voltage) {
    voltage_ = voltage;
    std::cout << name_ << " voltage set to " << voltage_ << " Volts.\n";
}

double PowerSupply::getVoltage() const { return voltage_; }

// Simple logic: voltage supports up to voltage/600 Tesla
bool PowerSupply::canSupportField(double field) const {
    return field <= (voltage_ / 600.0);
}

void PowerSupply::simulate() {
    if (status_)
        std::cout << name_ << " providing " << voltage_ << " Volts.\n";
    else
        std::cout << name_ << " is OFF.\n";
}
