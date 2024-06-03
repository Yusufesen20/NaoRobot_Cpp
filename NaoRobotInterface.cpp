#include <iostream>
#include "NaoRobotInterface.h"

using namespace std;

NaoRobotInterface::NaoRobotInterface(NaoRobotAPI* robotAPI) {
	this->robotAPI = robotAPI;
}

NaoRobotInterface::~NaoRobotInterface() {
	delete robotAPI;
}

void NaoRobotInterface::turnLeft() {
	robotAPI->turnRobot(LEFT);
}

void NaoRobotInterface::turnRight() {
	robotAPI->turnRobot(RIGHT);
}

void NaoRobotInterface::forward() {
	robotAPI->moveRobot(FORWARD);
}

void NaoRobotInterface::backward() {
	robotAPI->moveRobot(BACKWARD);
}

void NaoRobotInterface::moveLeft() {
	robotAPI->moveRobot(LEFT);
}

void NaoRobotInterface::moveRight() {
	robotAPI->moveRobot(RIGHT);
}

void NaoRobotInterface::stop() {
	robotAPI->stopRobot();
}

void NaoRobotInterface::print() {
	cout << "POSE         : (X) " << robotAPI->getX() << " meters, "
		<< "(Y) " << robotAPI->getY() << " meters, "
		<< "(Th) " << robotAPI->getTh() << " degrees" << endl << endl;
}

Pose NaoRobotInterface::getPose() {
	return Pose(robotAPI->getX(), robotAPI->getY(), robotAPI->getTh());
}