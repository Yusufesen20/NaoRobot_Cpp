#pragma once
#include <string>
#include <vector>
#include "RobotInterface.h"
#include "SensorInterface.h"
#include "Pose.h"
#include "Path.h"
#include "Record.h"
#include "RobotOperator.h"

class RobotControl {
private:
	RobotInterface* robotInterface;
	Path path;
	Record record;
public:
	RobotControl(RobotInterface* robotInterface);
	~RobotControl();
	void turnLeft();
	void turnRight();
	void forward();
	void backward();
	void moveLeft();
	void moveRight();
	void stop();
	void addSensor(SensorInterface* sensor);
	void print();
	Pose getPose();
	void printSensor(string type);
	bool addToPath();
	void clearPath();
	bool recordPathToFile(string filename);
	bool openAccess(int port);
	bool closeAccess();
	bool recordSensorToFile(string filename, string sensorType);
};