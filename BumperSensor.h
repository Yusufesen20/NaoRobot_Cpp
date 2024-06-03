#pragma once
#include <string>
#include "NaoRobotSensorInterface.h"

class BumperSensor : public NaoRobotSensorInterface {
private:
	bool states[4];
public:
	BumperSensor();
	string getSensorType() const override;
	bool getState(int index);
	void updateSensor() override;
	bool checkTouch();
	string getSensorValue() override;
};
