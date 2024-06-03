#pragma once
#include <string>
#include <iostream>

using namespace std;

class SensorInterface {
private:
	string sensorType;
public:
	virtual void updateSensor() = 0;
	virtual string getSensorValue() = 0;
	virtual string getSensorType() const = 0;
	virtual ~SensorInterface() {}
};
