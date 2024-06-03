#pragma once
#include "NaoRobotAPI.h"
#include "RobotInterface.h"

class NaoRobotInterface : public RobotInterface {
private:
	NaoRobotAPI* robotAPI;
public:
	NaoRobotInterface(NaoRobotAPI* robotAPI);
	~NaoRobotInterface();
	void turnLeft() override;
	void turnRight() override;
	void forward() override;
	void backward() override;
	void moveLeft() override;
	void moveRight() override;
	void stop() override;
	void print() override;
	Pose getPose() override;
};
