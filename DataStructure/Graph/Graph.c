#ifndef GRAPH_C
#define GRAPH_C

#include <stdio.h>
#include "Graph.h"
#include "../Stack/Stack.c"

#define N_ARRIVE -1

Status initGraph(Graph* graph) {
	graph->top = -1;
	int i, j;
	for (i = 0; i < NODENUM; i++) {
		graph->nodes[i] = NULL;
		for (j = 0; j < NODENUM; j++) {
			graph->graph[i][j] = (i == j) ? 0 : N_ARRIVE;
		}
	}
	return OK;
}

Status prime(const Graph graph, int start) {
	Stack visited;
	initStack(&visited);
	push(visited, start);
	int i, j, res = 0;
	while (visited->length < NODENUM) {
		int temp = -1, now_length = INT_MAX, length = visited->length;
		Boolean allVisited = TRUE;
		for (i = 0; i < length; ++i) {
			int node = visited->data[i];
			int l;
			for (j = 0; j < NODENUM; ++j) {
				if (graph.graph[node][j] == N_ARRIVE || j == node || search(visited, j, &l)) continue;
				if (now_length > graph.graph[node][j]) {
					temp = j;
					now_length = graph.graph[node][j];
				}
				allVisited = FALSE;
			}
		}
		if (allVisited) break;
		if (temp != -1) {
			push(visited, temp);
			res += now_length;
			printf("当前结点栈：");
			printStack(visited);
			puts("");
			printf("当前权重和：%d\n", res);
		}
	}
	if (visited->length < NODENUM) {
		puts("无法生成最小生成树，图不连通或存在孤立结点。");
		return OK;
	}
	puts("最小生成树如下：");
	for (i = 0; i < NODENUM; ++i) {
		if (i != 0) printf(" to ");
		printString(graph.nodes[visited->data[i]]);
	}
	printf("\n最小权重为：%d\n", res);
	destroyStack(&visited);
	return OK;
}

Status dijkstra(const Graph graph, int start, int end, const Graph otherGraph) {
	int dist[NODENUM];
	int visited[NODENUM];
	int prev[NODENUM];

	int i, j, min, src;
	for (i = 0; i < NODENUM; ++i) {
		dist[i] = INT_MAX;
		visited[i] = 0;
		prev[i] = -1;
	}

	dist[start] = 0;

	for (i = 0; i < NODENUM; ++i) {
		min = INT_MAX;
		for (j = 0; j < NODENUM; ++j) {
			if (!visited[j] && dist[j] < min) {
				min = dist[j];
				src = j;
			}
		}

		visited[src] = 1;

		for (j = 0; j < NODENUM; ++j) {
			if (!visited[j] && graph.graph[src][j] != N_ARRIVE && dist[src] + graph.graph[src][j] < dist[j]) {
				dist[j] = dist[src] + graph.graph[src][j];
				prev[j] = src;
			}
		}
	}

	if (dist[end] == INT_MAX) {
		printf("没有最短路\n");
	} else {
		printf("最短路径为：");
		int path[NODENUM], count = 0;
		int cur = end;
		while (cur != start) {
			path[count++] = cur;
			cur = prev[cur];
		}
		path[count++] = start;
		for (i = count - 1; i >= 0; --i) {
			if (i != count - 1) printf(" to ");
			printf("%s", graph.nodes[path[i]]);
		}
		puts("");
		printf("最短路长度为：%d\n", dist[end]);

		int totalCost = 0;
		for (i = count - 1; i > 0; --i) {
			totalCost += otherGraph.graph[path[i]][path[i-1]];
		}
		printf("在另一张图上的消耗总值为：%d\n", totalCost);
	}
	return OK;
}

Status printGraph(const Graph toPrint) {
	if (toPrint.nodes == NULL || toPrint.graph == NULL) return ERROR;
	int i, j;
	printf("            ");
	for (i = 0; i < NODENUM; ++i) printf("%12s", toPrint.nodes[i]);
	puts("");
	for (i = 0; i < NODENUM; ++i) {
		printf("%12s", toPrint.nodes[i]);
		for (j = 0; j < NODENUM; ++j) {
			printf("%12d",toPrint.graph[i][j]);
		}
		puts("");
	}
	return OK;
}

Status addEdge(Graph* toAdd, int startPlace, int endPlace, int weight) {
	(*toAdd).graph[startPlace][endPlace] = weight;
	return OK;
}

int getNodeIndex(Graph* g, char* toGet) {
	int i;
	for (i = 0; i <= g->top; ++i) {
		if (strcmp(g->nodes[i], toGet) == 0) return i;
	}
	g->top += 1;
	g->nodes[g->top] = (char *) malloc (sizeof(char) * strlen(toGet));
	strcpy(g->nodes[g->top], toGet);
	for (i = 0; i < NODENUM; ++i) printf("%3d\t%16s\n", i, g->nodes[i]);
	return (g->top);
}

#endif
