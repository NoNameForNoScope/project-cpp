#include "SmartLight.h"
#include <string>

void SmartLight::turnOn()
{
	if (isOn == true)
	{
		Logger::get_instance().append_file("Becul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este deja pornit");
		return;
	}
	isOn = true;
	Logger::get_instance().append_file("Becul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " a fost pornit");
}

void SmartLight::turnOff()
{
	if (isOn != true)
	{
		Logger::get_instance().append_file("Becul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este deja oprit");
		return;
	}
	isOn = false;
	Logger::get_instance().append_file("Becul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " a fost oprit");
}

void SmartLight::getStatus()
{
	std::string msg;
	msg = "Becul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " - " + ((isOn == true) ? "PORNIT" : "OPRIT") + " cu luminozitatea: " + std::to_string(_brightness);
	std::cout << msg << std::endl;
}

void SmartLight::change_bright(int delta) {
	if (!isOn) {
		Logger::get_instance().append_file("Becul " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este oprit");
		return;
	}
	if (delta > 0) {
		if (delta + _brightness < 100) {
			_brightness += delta;
			Logger::get_instance().append_file("Becului " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " i-a fost crescuta luminozitatea la: " + std::to_string(_brightness));
		}
		else {
			_brightness = 100;
			Logger::get_instance().append_file("Becului " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " i-a fost crescuta luminozitatea la: " + std::to_string(_brightness));
		}
	}
	if (delta < 0) {
		if (_brightness - delta > 0) {
			_brightness -= delta;
			Logger::get_instance().append_file("Becului " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " i-a fost scazuta luminozitatea la: " + std::to_string(_brightness));
		}
		else {
			_brightness = 0;
			Logger::get_instance().append_file("Becului " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " i-a fost scazuta luminozitatea la: " + std::to_string(_brightness));
		}
	}
}