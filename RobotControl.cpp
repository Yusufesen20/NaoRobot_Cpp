#include <iostream>
#include "RobotControl.h"

using namespace std;

RobotControl::RobotControl(RobotInterface* robotInterface) {
	this->robotInterface = robotInterface;
}

RobotControl::~RobotControl() {
	delete robotInterface;
}

void RobotControl::turnLeft() {
	robotInterface->turnLeft();
}

void RobotControl::turnRight() {
	robotInterface->turnRight();
}

void RobotControl::forward() {
	robotInterface->forward();
}

void RobotControl::backward() {
	robotInterface->backward();
}

void RobotControl::moveLeft() {
	robotInterface->moveLeft();
}

void RobotControl::moveRight() {
	robotInterface->moveRight();
}

void RobotControl::stop() {
	robotInterface->stop();
	robotInterface->updateSensors();
}

void RobotControl::addSensor(SensorInterface* sensor) {
	robotInterface->addSensor(sensor);
}

void RobotControl::print() {
	robotInterface->print();
}

Pose RobotControl::getPose() {
	return robotInterface->getPose();
}

void RobotControl::printSensor(string type) {
	for (SensorInterface* sensor : robotInterface->getSensorList()) {
		if (sensor->getSensorType() == type) {
			std::cout << "Sensor Type: " << type << ", Value: " << sensor->getSensorValue() << std::endl;
			return;
		}
	}
	cout << "Sensor of type " << type << " not found." << std::endl;
}

bool RobotControl::addToPath() {
	Pose currentPose = robotInterface->getPose();
	path.addPos(currentPose);
}

void RobotControl::clearPath() {
	path.~Path();
}
