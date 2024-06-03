#pragma once
#include <vector>
#include "SensorInterface.h"
#include "Pose.h"

using namespace std;

class RobotInterface{
private:
	Pose* position;
	int status;
	vector<SensorInterface*> sensorList;
public:
	virtual ~RobotInterface() {
		for (SensorInterface* sensor : sensorList) {
			delete sensor;
		}
		sensorList.clear();
	}
	const vector<SensorInterface*>& getSensorList() const {
		return sensorList;
	}
	virtual Pose getPose() = 0;
	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;
	virtual void forward() = 0;
	virtual void backward() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void stop() = 0;
	virtual void print() = 0;
	void updateSensors();
	void addSensor(SensorInterface* sensor);
};
