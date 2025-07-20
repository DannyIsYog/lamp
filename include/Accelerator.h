#ifndef ACCELERATOR_H
#define ACCELERATOR_H

#include "Magnet.h"
#include "PowerSupply.h"
#include <vector>
#include <memory>

class Accelerator {
    std::vector<std::shared_ptr<Device>> devices_;

public:
    void addDevice(const std::shared_ptr<Device>& device);
    void simulateAll();
    void turnOnAll();
    void turnOffAll();
};

#endif
