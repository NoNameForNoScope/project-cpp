#pragma once
#include "Devices.h"
#include "Logger.h"
#include <iostream>

class SecurityCamera : public Devices
{
private:
	bool isRecording;
public:
	
	SecurityCamera(std::string& producer, std::string& name, int warranty) :
		Devices(producer, name, warranty),
		isRecording(false)
	{}


	void turnOn() override;
	void turnOff() override;
	void getStatus() override;
	void start_recording();
	void stop_recording();

};

