#include "Device.h"
#include <iostream>

Device::Device(const std::string& name)
    : name_(name), status_(false) {}

Device::~Device() {}

void Device::turnOn() {
    status_ = true;
    std::cout << name_ << " turned ON.\n";
}

void Device::turnOff() {
    status_ = false;
    std::cout << name_ << " turned OFF.\n";
}

bool Device::isOn() const { return status_; }
std::string Device::getName() const { return name_; }
