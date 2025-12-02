#pragma once
#include "Devices.h"
#include <iostream>
#include "Logger.h"
enum class Mod {
	BUNICA,
	AUTOMAT
};

class SmartThermostat:public Devices
{

private:
	int _temp;
	Mod _mode;
public:
	SmartThermostat(std::string& producer, std::string& name, int warranty, Mod mode) :
		Devices(producer, name, warranty),
		_temp(20),
		_mode(mode)
	{}

	void turnOn() override;
	void turnOff() override;
	void getStatus() override;
	void change_mode(Mod mod1);
	void change_temp(int delta);

};

