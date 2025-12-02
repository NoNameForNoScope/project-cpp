#include "SmartHub.h"
#include "SmartLight.h"       
#include "SmartThermostat.h"  
#include "SecurityCamera.h"    
#include <string>
void SmartHub::add_device(Devices* d)
{
	int id = d->getId();
	home[id] = d;

}

void SmartHub::remove_device(int id)
{
	if (home.erase(id)) {
		Logger::get_instance().append_file("A fost sters device-ul cu id-ul: " + std::to_string(id));
	}
	else {
		Logger::get_instance().append_file("Nu a fost gasit device-ul cu id-ul: " + std::to_string(id));
	}

}

void SmartHub::show_device_list()
{
	for (auto& it : home) {
		auto d = it.second;
		d->getStatus();
		std::cout << std::endl;
	}
}

void SmartHub::turnOn_all()
{
	for (auto& it : home) {
		auto d = it.second;
		d->turnOn();
	}

}

void SmartHub::turnOff_all()
{

	for (auto& it : home) {
		auto d = it.second;
		d->turnOff();
	}

}

void SmartHub::individual_control(int id)
{
	auto d = home[id];
	if (auto light = dynamic_cast<SmartLight*>(d)){
		light->turnOn();
		light->getStatus();
		light->turnOff();
	}
	else if (auto camera = dynamic_cast<SecurityCamera*>(d)) {
		camera->turnOn();
		camera->start_recording();
		camera->getStatus();
		camera->stop_recording();
		camera->turnOff();
	}
	else if (auto therm = dynamic_cast<SmartThermostat*>(d)) {
		therm->turnOn();
		therm->getStatus();
		therm->change_mode(Mod::BUNICA);
		therm->turnOff();
	}


}

void SmartHub::individual_status(int id)
{
	auto d = home[id];
	d->getStatus();

}
