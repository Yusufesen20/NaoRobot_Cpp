#include <iostream>
#include "BumperSensor.h"

using namespace std;

BumperSensor::BumperSensor() : NaoRobotSensorInterface(robotAPI) {
	for (int i = 0; i < 4; i++) {
		states[i] = false;
	}
}

string BumperSensor::getSensorType() const {
	return "Bumper";
}

bool BumperSensor::getState(int index) {
	return states[index];
}

void BumperSensor::updateSensor() {
	robotAPI->getFootBumpers(states[0], states[1], states[2], states[3]);
}

bool BumperSensor::checkTouch() {
	for (int i = 0; i < 4; i++) {
		if (states[i]) {
			return true;
		}
	}
	return false;
}

string BumperSensor::getSensorValue() {
	string result = "";
	for (int i = 0; i < 4; i++) {
		result += "[" + to_string(i) + "]" + ": ";
		result += to_string(states[i]) + " ";
		
	}
	return result;
}
