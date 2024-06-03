#include <string>
#include <fstream>
#include <iostream>
#include "Record.h"

using namespace std;

void Record::openFile(const string& filename) {
	file.open(filename, ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Error opening file: " << filename << endl;
	}
}

void Record::closeFile() {
	file.close();
}

void Record::setFileName(const string name) {
	fileName = name;
}

string Record::readLine() {
	string line;
	getline(file, line);
	return line;
}

void Record::writeLine(const string& str) {
	file << str << endl;
}

Record* Record::operator<<(const string& str) {
	writeLine(str);
	return this;
}

Record* Record::operator>>(string& str) {
	str = readLine();
	return this;
}
