#include "SmartThermostat.h"
#include <string>

void SmartThermostat::turnOn()
{
	if (isOn == true)
	{
		Logger::get_instance().append_file("Termostatul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este deja pornit");
		return;
	}
	isOn = true;
	Logger::get_instance().append_file("Termostatul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " a fost pornit");
}

void SmartThermostat::turnOff()
{
	if (isOn != true)
	{
		Logger::get_instance().append_file("Termostatul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este deja oprit");
		return;
	}
	isOn = false;
	Logger::get_instance().append_file("Termostatul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " a fost oprit");
}

void SmartThermostat::getStatus()
{
	std::string msg;
	msg = "Termostatul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " - " + ((isOn == true) ? "PORNIT" : "OPRIT") + "  in modul:  " + ((_mode == Mod::BUNICA) ? "BUNICA" : "AUTOMAT") + "  cu temperatura: " + std::to_string(_temp);
	std::cout << msg << std::endl;
}

void SmartThermostat::change_mode(Mod mod1)
{
	_mode = mod1;
}

void SmartThermostat::change_temp(int delta)
{
	if (!isOn) {
		Logger::get_instance().append_file("Termostatul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este oprit");
		return;
	}
	if (delta > 0) {
		_temp += delta;
		Logger::get_instance().append_file("Termostatului " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + "  i-a crescut temperatura la: " + std::to_string(_temp));
	}
	if (delta < 0) {
		_temp -= delta;
		Logger::get_instance().append_file("Termostatului " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + "  i-a scazut temperatura la: " + std::to_string(_temp));
	}
}