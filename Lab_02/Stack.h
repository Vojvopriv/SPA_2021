#pragma once






//#include "Graph.h"	// Circular include dependency - ako u  "Graph.h"  ukljucim  "Stack.h"  i u  "Stack.h"  ukljucim  "Graph.h" -ERROR
class Graph;			// Forward declaration


class Node {
public:
	int n;
	Node* next;

	Node(int num = 0, Node* nxt = nullptr) : n(num), next(nxt) {}
	~Node() { delete next; }
};

void push(Node** tos, const Graph*, int node);
int pop(Node** tos);


