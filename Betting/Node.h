#pragma once
#include "Bet.h"

class Node
{
public:
	Bet* data;
	Node* next;
	Node(Bet* p) : data(p), next(nullptr) {}
	~Node();
};

