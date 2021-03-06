#include "Graph.h"

Graph g(6);



int main(int argc, char* argv[])
{
	Initialise(1024, 720, false, "My Awesome Graph");
	SetBackgroundColour(SColour(0, 100, 200, 50));

	//Edge from 0 to 1
	Edge e1;
	e1.g_nStart = g.g_nNodes[0];
	e1.g_nEnd = g.g_nNodes[1];
	g.g_nNodes[0]->g_nEdges.push_back(e1);

	//Edge from 1 to 2
	Edge e2;
	e2.g_nStart = g.g_nNodes[1];
	e2.g_nEnd = g.g_nNodes[2];
	g.g_nNodes[1]->g_nEdges.emplace_back(e2);

	//Edge from 2 to 0
	Edge e3;
	e3.g_nStart = g.g_nNodes[2];
	e3.g_nEnd = g.g_nNodes[0];
	g.g_nNodes[2]->g_nEdges.push_back(e3);

	//Edge from 2 to 3
	Edge e4;
	e4.g_nStart = g.g_nNodes[2];
	e4.g_nEnd = g.g_nNodes[3];
	g.g_nNodes[2]->g_nEdges.push_back(e4);

	//Edge from 3 to 4
	Edge e5;
	e5.g_nStart = g.g_nNodes[3];
	e5.g_nEnd = g.g_nNodes[4];
	g.g_nNodes[3]->g_nEdges.push_back(e5);

	//Edge from 0 to 5
	Edge e6;
	e6.g_nStart = g.g_nNodes[0];
	e6.g_nEnd = g.g_nNodes[5];
	g.g_nNodes[0]->g_nEdges.push_back(e6);

	//Edge from 5 to 4
	Edge e7;
	e7.g_nStart = g.g_nNodes[5];
	e7.g_nEnd = g.g_nNodes[4];
	g.g_nNodes[5]->g_nEdges.push_back(e7);
	
	//Edge from 5 to 3
	Edge e8;
	e8.g_nStart = g.g_nNodes[5];
	e8.g_nEnd = g.g_nNodes[3];
	g.g_nNodes[5]->g_nEdges.push_back(e8);

	g.PrintNodes();
	std::cout << "Select a node to follow." << std::endl;

	do
	{
		ClearScreen();


		g.CurrentNode = g.g_nNodes[1];
		g.PrintNeighbors(*g.g_nNodes[g.CurrentNode->NodeNumber]);


	} while (!FrameworkUpdate());
	g.~Graph();
	
	Shutdown();
	return 0;
}