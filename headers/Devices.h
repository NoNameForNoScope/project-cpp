#pragma once
#include <iostream>
#include <string>

class Devices
{
protected:
    static int next_id;
    int _id;
    std::string _producer;
    std::string _name;
    int _warranty;
    bool isOn;

public:
    Devices(const std::string& producer, const std::string& name, int warranty) :
        _producer(producer),
        _name(name),
        _warranty(warranty),
        _id(next_id++),
        isOn(false)
    {}

    virtual ~Devices() = default;  

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;

    virtual int getId() const { return _id; } 
};