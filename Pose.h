#pragma once

class Pose {
private:
	double x;
	double y;
	double th;
public:
	Pose();
	Pose(double x, double y, double th);
	~Pose();
	double getX();
	double getY();
	double getTh();
	void setX(double x);
	void setY(double y);
	void setTh(double th);
	bool operator==(const Pose& other);
	Pose operator+(const Pose& other);
	Pose operator-(const Pose& other);
	Pose& operator+=(const Pose& other);
	Pose& operator-=(const Pose& other);
	bool operator<(const Pose& other);
	double findDistanceTo(Pose& other);
	double findAngleTo(Pose& other);
	void getPose(double& _x, double& _y, double& _th);
	void setPose(double _x, double _y, double _th);
	friend istream& operator>>(istream& is, Pose& pose)
};
