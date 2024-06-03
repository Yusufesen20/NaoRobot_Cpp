#include "Pose.h"
#include <iostream>
#include <math.h>


using namespace std;

Pose::Pose() {
	x = 0;
	y = 0;
	th = 0;
}

Pose::Pose(double x, double y, double th) {
	this->x = x;
	this->y = y;
	this->th = th;
}

Pose::~Pose() {
	
}

double Pose::getX() {
	return x;
}

double Pose::getY() {
	return y;
}

double Pose::getTh() {
	return th;
}

void Pose::setX(double x) {
	this->x = x;
}

void Pose::setY(double y) {
	this->y = y;
}

void Pose::setTh(double th) {
	this->th = th;
}

bool Pose::operator==(const Pose& other) {
	return (x == other.x && y == other.y && th == other.th);
}

Pose Pose::operator+(const Pose& other) {
	return Pose(x + other.x, y + other.y, th + other.th);
}

Pose Pose::operator-(const Pose& other) {
	return Pose(x - other.x, y - other.y, th - other.th);
}

Pose& Pose::operator+=(const Pose& other) {
	x += other.x;
	y += other.y;
	th += other.th;
	return *this;
}

Pose& Pose::operator-=(const Pose& other) {
	x -= other.x;
	y -= other.y;
	th -= other.th;
	return *this;
}

bool Pose::operator<(const Pose& other) {
	return (x < other.x && y < other.y && th < other.th);
}

double Pose::findDistanceTo(Pose& other) {
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

double Pose::findAngleTo(Pose& other) {
	return atan2(other.y - y, other.x - x);
}

void Pose::getPose(double& _x, double& _y, double& _th) {
	_x = x;
	_y = y;
	_th = th;
}

void Pose::setPose(double _x, double _y, double _th) {
	x = _x;
	y = _y;
	th = _th;
}

istream& operator>>(istream& is, Pose& pose) {
	is >> pose.x >> pose.y >> pose.th;
	return is;
}