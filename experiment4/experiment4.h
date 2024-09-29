#ifndef EXPERIMENT4_H
#define EXPERIMENT4_H

#include "../DataStructure/Graph/Graph.c"

Status minRoute(Graph graph, Graph other);
Status minTree(Graph graph);
Status parseRouteInfo(char* phrase, Graph* distanceGraph, Graph* priceGraph);
Status loadGraphFromFile(Graph* distanceGraph, Graph* priceGraph);

#endif
