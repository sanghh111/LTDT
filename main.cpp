#include "graph.h"
#include "graph.cpp"
int main()
{
	int choose;
   // khoi tao do thi
	Graph g(8);

	// tao canh noi giua cac dinh ke
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(2, 6);
	g.addEdge(3, 4);
	g.addEdge(3, 8);
	g.addEdge(4, 8); 
	g.addEdge(5, 8);
	g.addEdge(6, 7); 
	g.addEdge(6, 8);

	printf("------------------Menu----------------- ");
	printf("\n1. BFS");
	printf("\n2. DFS\n");
	scanf("\n%d", &choose);
	
	switch (choose)
	{
	case 1:
		g.BreadthFirstSearch(1, 7);
		break;
	
	case 2:
		g.DepthFirstSearch(1, 4);
		break;
	}
}


	
