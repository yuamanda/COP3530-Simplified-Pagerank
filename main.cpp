#include <iostream>
#include "AdjacencyList.h"
using namespace std;

int main()
{
    // create variables
    int no_of_lines, power_iterations;
    string from, to;
    AdjacencyList graph;

    // read in user input
    cin >> no_of_lines;
    cin >> power_iterations;

    // insert edges into the graph for no_of_lines
    for(int i = 0; i < no_of_lines; i++)
    {
        cin >> from;
        cin >> to;

        // insert vertices into the graph
        graph.insertEdge(from, to);
    }

    // create a graph object and get page ranks
    graph.PageRank(power_iterations);
}
