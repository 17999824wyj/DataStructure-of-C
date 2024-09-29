#ifndef GRAPH_H
#define GRAPH_H

#include "../../config/status.h"

#define NODENUM 22

typedef struct Graph {
	char* nodes[NODENUM]; /* the dictionary of node name */
	int top; /* record the top of stack */
	int graph[NODENUM][NODENUM]; /* adj matrix */
} Graph;

/* functions define are as bellow */

/**@Author    : wyj
 * @function  : to initialize a new Graph
 * @parameter : a Graph's address to recieve this new Graph
 * @return    : initialize successfully or not
 */
Status initGraph(Graph* graph);

/**@Author    : wyj
 * @function  : to find the index of the given string on the given Graph
 				if not found, the given string will be put on the nodes!
 * @parameter : a Graph's to be search on, the target
 * @return    : the index of the wanted one
 */
int getNodeIndex(Graph* g, char* toGet);

/**@Author    : wyj
 * @function  : Algorithm Prime
 * @parameter : a Graph
 * @return    : run successfully or not
 */
Status prime(const Graph graph, int start);

/**@Author    : wyj
 * @function  : Algorithm Floyd
 * @parameter : a Graph, the start, the end, the other Graph to compare
 * @return    : run successfully or not
 */
Status dijkstra(const Graph graph, int start, int end, const Graph otherGraph);

/**@Author    : wyj
 * @function  : to print the given Graph
 * @parameter : a Graph's to be printed
 * @return    : print successfully or not
 */
Status printGraph(const Graph toPrint);

/**@Author    : wyj
 * @function  : to add a given edge to the given Graph
 * @parameter : the address of the Graph to be added
 * @return    : add successfully or not
 */
Status addEdge(Graph* toAdd, int startPlace, int endPlace, int weight);

#endif
