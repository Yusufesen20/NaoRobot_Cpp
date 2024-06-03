#pragma once
#include <string>
#include "Encryption.h"

using namespace std;

class RobotOperator {
private:
	string name;
	string surname;
	unsigned int accessCode;
	bool accessState;
public:
	RobotOperator(string name, string surname, unsigned int accessCode);
	int encryptCode(int code);
	int decryptCode(int encryptedCode);
	bool checkAccessCode(int code);
	void print();
};
