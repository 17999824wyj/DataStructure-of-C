#ifndef EXPERIMENT4_C
#define EXPERIMENT4_C

#include "experiment4.h"
#include <string.h>

Status minRoute(Graph graph, Graph other) {
	int start=-1, end=-1, i;
	for (i = 0; i < NODENUM; ++i) printf("%3d\t%16s\n", i, graph.nodes[i]);
	printStars(24);
	puts("");
	printf("StartNode >> ");
	scanf("%d",&start);
	if(start < 0 || start > NODENUM - 1) return ERROR;
	printf("EndNode >> ");
	scanf("%d",&end);
	if(end < 0 || end > NODENUM - 1) return ERROR;
	if(!dijkstra(graph, start, end, other)) return ERROR;
	return OK;
}

Status minTree(Graph graph) {
	int begin=-1, i;
	for (i = 0; i < NODENUM; ++i) printf("%3d\t%16s\n", i, graph.nodes[i]);
	printStars(24);
	puts("");
	printf("BeginNode >> ");
	scanf("%d",&begin);
	if(begin < 0 || begin > NODENUM-1) return ERROR;
	if(!prime(graph, begin)) return ERROR;
	return OK;
}

Status loadGraphFromFile(Graph* distanceGraph, Graph* priceGraph) {
	FILE *fptr;
	char question[100];
	fptr = fopen("./datas/services.txt", "r");
	if (fptr == NULL) {
		printf("Failed to open file\n");
		return ERROR;
	}
	while (fgets(question, 100, fptr)) {
		puts("#####################");
		printString(question);
		parseRouteInfo(question, distanceGraph, priceGraph);
		puts("");
	}
	fclose(fptr);
	return OK;
}

Status parseRouteInfo(char* phrase, Graph* distanceGraph, Graph* priceGraph) {
	char* startPlace = getWord(phrase, 1);
	char* endPlace = getWord(phrase, 2);
	removeLastChar(startPlace);
	removeLastChar(endPlace);
	int price = atoi(getWord(phrase, 3));
	int distance = atoi(getWord(phrase, 4));

	int startIndex = getNodeIndex(priceGraph, startPlace);
	int endIndex = getNodeIndex(priceGraph, endPlace);
	if (!(addEdge(priceGraph, startIndex, endIndex, price))) return ERROR;

	startIndex = getNodeIndex(distanceGraph, startPlace);
	endIndex = getNodeIndex(distanceGraph, endPlace);
	if (!(addEdge(distanceGraph, startIndex, endIndex, distance))) return ERROR;

	return OK;
}

#endif
