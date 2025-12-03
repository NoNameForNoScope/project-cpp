#include "SecurityCamera.h"
#include <string>

void SecurityCamera::turnOn()
{
	if (isOn == true)
	{
		Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este deja pornita");
		return;
	}
	isOn = true;
	Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " a fost pornita");
}

void SecurityCamera::turnOff()
{
	if (isOn != true)
	{
		Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " este deja oprita");
		return;
	}
	isOn = false;
	isRecording = false;  // FIX: Oprește și filmarea când oprești camera!
	Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " a fost oprita");
}

void SecurityCamera::getStatus()
{
	std::string msg;
	msg = "Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " - " + ((isOn == true) ? "PORNITA" : "OPRITA") + " filmare activa: " + ((isRecording == true) ? "FILMEAZA" : "NU FILMEAZA");
	std::cout << msg << std::endl;
}

void SecurityCamera::start_recording()
{
	if (!isOn) {
		return;
	}
	if (isRecording) {
		Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " filmeaza deja");
		return;
	}
	isRecording = true;
	Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " a inceput sa filmeze");
}

void SecurityCamera::stop_recording()
{
	if (!isOn) {
		return;
	}
	if (!isRecording) {
		Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " nu filmeaza");
		return;
	}
	isRecording = false;
	Logger::get_instance().append_file("Camera " + _producer + " " + _name + " cu ID: " + std::to_string(_id) + " s-a oprit din a filma");
}