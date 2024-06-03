#pragma once
#include <iostream>
#include "Node.h"

class Path {
private:
	Node* head;
	Node* tail;
	int number;
public:
	Path();
	~Path();
	void addPos(Pose pose);
	void print();
	Pose getPos(int index);
	Pose operator[](int index);
	bool removePos(int index);
	bool insertPos(int index, Pose pose);
	friend ostream& operator<<(ostream& os, const Path& path);
	friend istream& operator>>(istream& is, Path& path);
};
