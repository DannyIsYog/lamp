#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    std::string name_;
    bool status_;

public:
    Device(const std::string& name);
    virtual ~Device();

    virtual void turnOn();
    virtual void turnOff();
    virtual void simulate() = 0;

    bool isOn() const;
    std::string getName() const;
};

#endif
