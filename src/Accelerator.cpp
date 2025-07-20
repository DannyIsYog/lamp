#include "Accelerator.h"
#include <iostream>

void Accelerator::addDevice(const std::shared_ptr<Device>& device) {
    devices_.push_back(device);
}

void Accelerator::simulateAll() {
    std::cout << "\n--- Accelerator Simulation ---\n";
    for (auto& dev : devices_)
        dev->simulate();
}

void Accelerator::turnOnAll() {
    for (auto& dev : devices_)
        dev->turnOn();
}

void Accelerator::turnOffAll() {
    for (auto& dev : devices_)
        dev->turnOff();
}
