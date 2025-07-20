#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include "Device.h"

class PowerSupply : public Device {
    double voltage_;
public:
    PowerSupply(const std::string& name, double voltage = 0.0);

    void setVoltage(double voltage);
    double getVoltage() const;

    bool canSupportField(double field) const;

    void simulate() override;
};

#endif
