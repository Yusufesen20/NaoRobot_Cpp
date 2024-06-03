#include <iostream>
#include <string>
#include "SonarSensor.h"

using namespace std;

SonarSensor::SonarSensor() : NaoRobotSensorInterface(robotAPI) {
	ranges[0] = 0;
	ranges[1] = 0;
}

string SonarSensor::getSensorType() const {
	return "Sonar";
}

double SonarSensor::getRange(int index) {
	return ranges[index];
}

void SonarSensor::updateSensor() {
	robotAPI->getSonarRange(ranges[0], ranges[1]);
}

double SonarSensor::getMin(int& index) {
	double min = ranges[0];
	index = 0;
	for (int i = 1; i < 2; i++) {
		if (ranges[i] < min) {
			min = ranges[i];
			index = i;
		}
	}
	return min;
}

double SonarSensor::getMax(int& index) {
	double max = ranges[0];
	index = 0;
	for (int i = 1; i < 2; i++) {
		if (ranges[i] > max) {
			max = ranges[i];
			index = i;
		}
	}
	return max;
}

double SonarSensor::operator[](int i) {
	return ranges[i];
}

string SonarSensor::getSensorValue() {
	string result = "";
	for (int i = 0; i < 2; i++) {
		result += "[" + to_string(i) + "]" + ": ";
		result += to_string(ranges[i]) + " ";
	}
	return result;
}