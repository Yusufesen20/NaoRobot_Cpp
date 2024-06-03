#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Record {
private:
	fstream file;
	string fileName;
public:
    void openFile(const string& filename);
    void closeFile();
    void setFileName(const string name);
    string readLine();
    void writeLine(const string& str);
    Record* operator<<(const string& str);
    Record* operator>>(string& str);

    /*friend ostream& operator<<(ostream& os, const Record& record);
    friend istream& operator>>(istream& is, Record& record);*/
};
