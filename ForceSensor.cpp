#include <iostream>
#include "ForceSensor.h"

using namespace std;

ForceSensor::ForceSensor() : NaoRobotSensorInterface(robotAPI) {
	force = 0;
}

string ForceSensor::getSensorType() const {
	return "Force";
}

double ForceSensor::getForce() {
	return force;
}

void ForceSensor::updateSensor() {
	force = robotAPI->getFootForce();
}

string ForceSensor::getSensorValue() {
	return to_string(force);
}

bool ForceSensor::checkFall() {
	if (force < 5) {
		return true;
	}
	else {
		return false;
	}
}
