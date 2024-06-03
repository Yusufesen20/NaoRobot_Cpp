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
        // NaoRobotSensorInterface'ýn güncelleme iþlemi
    }

    std::string getSensorType() const override {
        return "NaoRobotSensor";
    }

    std::string getSensorValue() override {
        // NaoRobotSensorInterface'ýn deðeri alma iþlemi
        return "";
    }
};
