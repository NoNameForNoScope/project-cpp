#pragma once
#include "Devices.h"
#include "Logger.h"
class SmartLight : public Devices
{
private:
	int _brightness;
public:
	SmartLight(std::string& producer, std::string& name, int warranty) :
		Devices(producer, name, warranty),
		_brightness(0) {}
		
	void turnOn() override;
	void turnOff() override;
	void getStatus() override;
	void change_bright(int delta);


};