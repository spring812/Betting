#pragma once
#include "Node.h"
#include "Bet.h"
#include <iostream>
#include <sstream>
#include <fstream>

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	void clear();
	LinkedList* find(string field, string value);
	void add(Bet* p);
	void LoadFromFile(string filename);
	void SaveToFile(string filename);
	int remove(string field, string value);
	bool isEmpty() { return head == nullptr; }
	void sort(string fiel, bool ascending);
	int getSize() const;
	Node* head;
private:
	Node* findById(int id);
	Node* findByP1(double p1);
	Node* findByX(double x);
	Node* findByP2(double p2);
	Node* findByCategory(string sport);
	void removeNode(Node* to_detele);
};

