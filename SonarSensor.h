#pragma once
#include <string>
#include "NaoRobotSensorInterface.h"

class SonarSensor : public NaoRobotSensorInterface {
private:
	double ranges[2];
public:
	SonarSensor();
	string getSensorType() const override;
	double getRange(int index);
	void updateSensor() override;
	double getMin(int &index);
	double getMax(int &index);
	double operator[](int i);
	string getSensorValue() override;
};
