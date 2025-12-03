#include <iostream>
#include "SmartHub.h"
#include "SmartLight.h"
#include "SmartThermostat.h"
#include "SecurityCamera.h"

int main() {
    std::string prod1 = "Philips";
    std::string name1 = "Hue";
    SmartLight* bec1 = new SmartLight(prod1, name1, 24);

    std::string prod2 = "Nest";
    std::string name2 = "Pro";
    SmartThermostat* termostat = new SmartThermostat(prod2, name2, 36, Mod::AUTOMAT);

    std::string prod3 = "Ring";
    std::string name3 = "Doorbell";
    SecurityCamera* camera = new SecurityCamera(prod3, name3, 12);

    SmartHub& hub = SmartHub::get_instance();
    hub.add_device(bec1);
    hub.add_device(termostat);
    hub.add_device(camera);

    std::cout << "Device list:\n";
    hub.show_device_list();

    std::cout << "Turning on all devices:\n";
    hub.turnOn_all();

    std::cout << "Changing brightness:\n";
    bec1->change_bright(50);
    bec1->getStatus();

    std::cout << "Starting recording:\n";
    camera->start_recording();
    camera->getStatus();

    std::cout << "Changing temp:\n";
    termostat->change_temp(5);
    termostat->getStatus();

    std::cout << "Turning off all devices:\n";
    hub.turnOff_all();
    hub.show_device_list();

    hub.remove_device(2);

    std::cout << "Device-uri ramase:\n";
    hub.show_device_list();

    return 0;
}