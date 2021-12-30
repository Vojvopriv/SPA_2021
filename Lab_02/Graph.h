#pragma once


#include<iostream>

//#include "Stack.h"						// Circular include dependency - ako u  "Graph.h"  ukljucim  "Stack.h"  i u  "Stack.h"  ukljucim  "Graph.h" -ERROR
class Node;									// Forward declaration                               


#define MAX 30




class Graph {
private:
	int n;								// Dimenzija matrice
	int nodes[MAX + 1];					// Imena cvorova
	int ms[MAX + 1][MAX + 1];			// Matrica susjednosti

public:
	Graph() : n(MAX)
	{
		for (int i = 0; i <= MAX; i++)
			nodes[i] = i;										// Imena cvorova se postavljaju na 1, 2, 3, ...

		for (int i = 0; i <= MAX; i++)
			for (int j = 0; j <= MAX; j++)
				ms[i][j] = 0;									// Matrica susjednosti se postavlja na 0
	}

	inline int getNodeName(int x) const { return nodes[x]; }
	inline int getMS(int x, int y) const { return ms[x][y]; }


	// Funkcija koja obilazi graf po dubini i ispisuje redoslijed posjecivanja
	void DFS(int start_node) const;

	
	// Funkcija za ucitavanje grafa iz tekstualne datoteke
	void fInput_graph(std::string filename);


	// DFS obilazak za pronalazenje ciklusa
	void cycleDFS(Node** tos) const;

private:

	// Pomocna funkcija
	void DFS_visit(int start_node, bool* visit) const;
	
	// Pomocna funkcija
	void cycleDFS_visit(Node** tos, bool* visit, int start_node) const;
};

