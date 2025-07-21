#include "Accelerator.h"
#include "Magnet.h"
#include "PowerSupply.h"
#include "TemperatureSensor.h"
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    Accelerator accel;

    auto tempSensor = std::make_shared<TemperatureSensor>("Beam Temp Sensor", 22.0);
    auto magnet = std::make_shared<Magnet>("Dipole Magnet", 2.0);
    auto powerSupply = std::make_shared<PowerSupply>("Primary Power Supply", 1200);

    accel.addDevice(tempSensor);
    accel.addDevice(magnet);
    accel.addDevice(powerSupply);

    accel.turnOnAll();

    // Check if power supply supports desired magnet strength
    if (!powerSupply->canSupportField(magnet->getFieldStrength())) {
        std::cerr << "Error: PowerSupply voltage insufficient for magnet field!\n";
        magnet->setFieldStrength(powerSupply->getVoltage() / 600.0);
    }

    for (int cycle = 1; cycle <= 100; ++cycle) {
        std::cout << "\nSimulation cycle: " << cycle << "\n";
        powerSupply->simulate();
        magnet->simulate(*tempSensor);
        tempSensor->simulate();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    accel.turnOffAll();

    return 0;
}
