#include <iostream>
#include "RobotInterface.h"

using namespace std;

void RobotInterface::updateSensors() {
    for (SensorInterface* sensor : sensorList) {
        sensor->updateSensor();
    }
}

void RobotInterface::addSensor(SensorInterface* sensor) {
	sensorList.push_back(sensor);
}