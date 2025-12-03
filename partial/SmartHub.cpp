#include "SmartHub.h"
#include "SmartLight.h"       
#include "SmartThermostat.h"  
#include "SecurityCamera.h"    
#include <string>

SmartHub::~SmartHub() {
	for (auto& pair : home) {
		delete pair.second;
	}
	home.clear();
}

void SmartHub::add_device(Devices* d)
{
	if (!d) return;  
	int id = d->getId();
	home[id] = d;
}

void SmartHub::remove_device(int id)
{
	auto it = home.find(id);
	if (it != home.end()) {
		delete it->second;  
		home.erase(it);
		Logger::get_instance().append_file("A fost sters device-ul cu id-ul: " + std::to_string(id));
	}
	else {
		Logger::get_instance().append_file("Nu a fost gasit device-ul cu id-ul: " + std::to_string(id));
	}
}

void SmartHub::show_device_list()
{
	if (home.empty()) {
		std::cout << "Nu exista device-uri in hub.\n";
		return;
	}
	for (const auto& it : home) {
		it.second->getStatus();
	}
}

void SmartHub::turnOn_all()
{
	for (auto& it : home) {
		it.second->turnOn();
	}
}

void SmartHub::turnOff_all()
{
	for (auto& it : home) {
		it.second->turnOff();
	}
}

void SmartHub::individual_control(int id)
{
	auto it = home.find(id);  
	if (it == home.end()) {
		std::cout << "Device cu ID-ul " << id << " nu exista!\n";
		return;
	}

	auto d = it->second;

	if (auto light = dynamic_cast<SmartLight*>(d)) {
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
	auto it = home.find(id);
	if (it == home.end()) {
		std::cout << "Device cu ID-ul " << id << " nu exista\n";
		return;
	}
	it->second->getStatus();
}