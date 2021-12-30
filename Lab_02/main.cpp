#include <iostream>
#include <stdexcept>

#include "Graph.h"
#include "Stack.h"
#include "CanNotOpenFile.h"


#define FILENAME1 "graph1.txt"
#define FILENAME2 "graph2.txt"
#define FILENAME3 "graph3.txt"


int main()
{
	Graph graph1;
	Graph graph2;
	Graph graph3;

	Node* tos = nullptr;

	try {
		graph1.fInput_graph(FILENAME1);
		graph2.fInput_graph(FILENAME2);
		graph3.fInput_graph(FILENAME3);
	}
	catch (CanNotOpenFile& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error in function fInputGraph.\n";
	}
	

	graph1.DFS( 1 );
	graph2.DFS( 2 );
	graph3.DFS( 3 );

	std::cout << std::endl << std::endl;
	return 0;
}
