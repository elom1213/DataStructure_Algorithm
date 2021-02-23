#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _BUTTERFLY
#include "Graph.h"

void init(GraphType *graph)
{
  graph->total_node_num = 0;
  memset(graph->adj_mat, 0, sizeof(graph->adj_mat));
};

void set_total_node_num(GraphType* graph, int nodenum)
{
  graph->total_node_num = nodenum;
}

void set_edge(GraphType* graph, int src, int dist)
{
  graph->adj_mat[src][dist] = graph->adj_mat[dist][src] = 1;
}

