#pragma once
#include "NaoRobotAPI.h"
#include "SensorInterface.h"

class NaoRobotSensorInterface : public SensorInterface {
protected:
	NaoRobotAPI* robotAPI;
public:
	NaoRobotSensorInterface(NaoRobotAPI* robotAPI) {
		this->robotAPI = robotAPI;
	}
	virtual ~NaoRobotSensorInterface() {}
    void updateSensor() override {
        // NaoRobotSensorInterface'�n g�ncelleme i�lemi
    }

    std::string getSensorType() const override {
        return "NaoRobotSensor";
    }

    std::string getSensorValue() override {
        // NaoRobotSensorInterface'�n de�eri alma i�lemi
        return "";
    }
};
