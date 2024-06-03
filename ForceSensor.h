#pragma once
#include <string>
#include "NaoRobotSensorInterface.h"

class ForceSensor : public NaoRobotSensorInterface {
private:
	double force;
public:
	ForceSensor();
	string getSensorType() const override;
	double getForce();
	void updateSensor() override;
	string getSensorValue() override;
	bool checkFall();
	
};