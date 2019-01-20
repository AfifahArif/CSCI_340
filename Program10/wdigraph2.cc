/***
Afifah Arif
Program 10 - Weighted Graphs
Due Date: December 6, 2018
***/

#include <iostream>
#include <iomanip>

#include "/home/cs340/progs/18f/p10/wdigraph.h"

//depth-first search
void wdigraph::depth_first(int u) const
{
	static int ver = -1;
	static bool* visited = NULL;

	if (ver == -1)
	{
		ver = u;
		visited =  new bool(size);

		for(int i = 0; i < size; i++)
		visited[i] = false;
	}
	cout << label[u];
	visited[u] = true;

	for(int i = 0; i != size; i++)
	{
		if (adj_matrix[u][i] != 0 && visited[i] != true)
		{
			cout << "->";
			depth_first(i);
		}
	}

	if (u == ver)
	{
		cout << endl << endl;
		ver = -1;
		delete[] visited;
		visited = NULL;
	}
}

//prints graph
void wdigraph::print_graph() const
{
	//print num of nodes and matrix
	cout << "\nNo of Nodes = " << get_size() << endl << endl <<
		"Adjacency Matrix" << endl << endl;

	cout << "  |";
	for(int i = 0; i < (int) label.size(); i++)
	cout << "  " << label[i];
	cout << endl <<"--|";

	for(int i = 0; i < (int) label.size(); i++)
	cout << "---";
	cout << endl;

	for(int i = 0; i < (int) label.size(); i++)
	{
		cout << label[i] << " |";
		for(int j = 0; j < (int) label.size(); j++)
		{
			if(adj_matrix[i][j] != 0)
			cout << setw(3) << adj_matrix[i][j];
			else
			cout << setw(3) << "-";
		}
		if(i < (int) label.size() -1)
		cout << endl << "  |" << endl;
	}
}