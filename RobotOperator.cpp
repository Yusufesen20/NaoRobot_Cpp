#include <iostream>
#include "RobotOperator.h"

using namespace std;

RobotOperator::RobotOperator(string name, string surname, unsigned int accessCode) {
	Encryption encryption;
	this->name = name;
	this->surname = surname;
	this->accessCode = encryption.encrypt(accessCode);
	this->accessState = false;
}

int RobotOperator::encryptCode(int code) {
	Encryption encryption;
	return encryption.encrypt(code);
}

int RobotOperator::decryptCode(int encryptedCode) {
	Encryption encryption;
	return encryption.decrypt(encryptedCode);
}

bool RobotOperator::checkAccessCode(int code) {
	if (encryptCode(code) == accessCode) {
		accessState = true;
		return true;
	}
	else {
		accessState = false;
		return false;
	}
}

void RobotOperator::print() {
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Access Code: " << accessCode << endl;
	cout << "Access State: " << accessState << endl;
}