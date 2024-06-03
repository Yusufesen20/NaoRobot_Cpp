#include <iostream>
#include <string>
#include <fstream>
#include "Path.h"

using namespace std;

Path::Path() {
	head = nullptr;
	tail = nullptr;
	number = 0;
}

Path::~Path() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void Path::addPos(Pose pose) {
	Node* node = new Node();
	node->pose = pose;
	node->next = nullptr;
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		tail = node;
	}
	number++;
}

void Path::print() {
	Node* current = head;
	while (current != nullptr) {
		cout << "x: " << current->pose.getX() << " y: " << current->pose.getY() << " theta: " << current->pose.getTh() << std::endl;
		current = current->next;
	}
}

Pose Path::getPos(int index) {
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->pose;
}

Pose Path::operator[](int index) {
	return getPos(index);
}

bool Path::removePos(int index) {
	if (index < 0 || index >= number) {
		return false;
	}
	if (index == 0) {
		Node* temp = head;
		head = head->next;
		delete temp;
		number--;
		return true;
	}
	Node* current = head;
	for (int i = 0; i < index - 1; i++) {
		current = current->next;
	}
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	number--;
	return true;
}

bool Path::insertPos(int index, Pose pose) {
	if (index < 0 || index > number) {
		return false;
	}
	if (index == 0) {
		Node* node = new Node();
		node->pose = pose;
		node->next = head;
		head = node;
		number++;
		return true;
	}
	Node* current = head;
	for (int i = 0; i < index - 1; i++) {
		current = current->next;
	}
	Node* node = new Node();
	node->pose = pose;
	node->next = current->next;
	current->next = node;
	number++;
	return true;
}

ostream& operator<<(ostream& os, const Path& path) {
	Node* current = path.head;
	while (current != nullptr) {
		os << "x: " << current->pose.getX() << " y: " << current->pose.getY() << " theta: " << current->pose.getTh() << std::endl;
		current = current->next;
	}
	return os;
}

istream& operator>>(istream& is, Path& path) {
	Pose pos;
	is >> pos;
	path.addPos(pos);
	return is;
}