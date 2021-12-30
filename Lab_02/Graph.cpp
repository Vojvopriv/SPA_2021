#include "Graph.h"
#include "Stack.h"
#include "CanNotOpenFile.h"

#include<fstream>




void Graph::fInput_graph(std::string filename)
{
	std::ifstream FILE;
	FILE.open(filename, std::ios::in);

	if (!FILE.is_open()) throw CanNotOpenFile();


	FILE >> this->n;

	for (int i = 1; i <= this->n; i++)
		for (int j = 1; j <= this->n; j++)
			FILE >> this->ms[i][j];

	FILE.close();
}


void Graph::DFS(int start_node) const
{
	bool visit[MAX]{};

	std::cout << std::endl << "DFS visit: ";

	for (int i = 0; i <= this->n; i++)
		visit[i] = false;

	DFS_visit(start_node, visit);




	std::cout << "\b\b ";					// Brise zadnji znak " ->" tako sto naredba \b\b vraca kurzor dva puta unazad
	std::cout << "\b\b ";					// i onda se na to mjesto upise " "
	std::cout << std::endl << "-------------------------------------------" << std::endl;
}

void Graph::DFS_visit(int start_node, bool visit[]) const
{
	int i;

	visit[start_node] = true;

	std::cout << this->nodes[start_node] << " -> ";

	
	for (i = 1; i <= this->n; i++)
		if (this->ms[start_node][i] && !visit[i])
			DFS_visit(i, visit);
}


void Graph::cycleDFS(Node** tos) const
{
	int start_node = 0;
	bool visit[MAX + 1];

	for (int i = 1; i <= this->n; i++)
		visit[i] = false;
	
	cycleDFS_visit(tos, visit, start_node);
}

void Graph::cycleDFS_visit(Node** tos, bool* visit, int start_node) const
{
	int i;

	push(tos, this, this->nodes[start_node]);
	visit[start_node] = true;

	for (i = 1; i <= this->n; i++) {
		if (this->ms[start_node][i] && !visit[i])
			cycleDFS_visit(tos, visit, i);

	}

	// Search for cycles in stack
	// Print cycles to file

	pop(tos);
}
