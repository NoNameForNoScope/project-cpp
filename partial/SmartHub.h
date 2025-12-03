#pragma once
#include <iostream>
#include <map>
#include "Devices.h"
#include "Logger.h"
#include "SmartLight.h"
#include "SmartThermostat.h"
#include "SecurityCamera.h"

class SmartHub
{
	SmartHub(const SmartHub&) = delete;
	SmartHub& operator=(const SmartHub&) = delete;
	SmartHub() = default;
	
	~SmartHub();

public:
	static SmartHub& get_instance() {
		static SmartHub s_instance;
		return s_instance;
	}
	
	std::map<int, Devices*> home;


	void add_device(Devices* d);
	void remove_device(int id);
	void show_device_list();
	void turnOn_all();
	void turnOff_all();
	void individual_control(int id);
	void individual_status(int id);


};

