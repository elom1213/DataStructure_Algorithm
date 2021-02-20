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
  if(MAXSIZ < nodenum)
  {
    fprintf(stderr, "invalid max size\n");
    exit(1);
  }
  graph->total_node_num = nodenum;
}

void set_edge(GraphType* graph, int _s, int _v)
{
  if(_s > graph->total_node_num || _v > graph->total_node_num)
  {
    fprintf(stderr, "invalid input node\n");
    exit(1);
  }
  graph->adj_mat[_s][_v] = graph->adj_mat[_v][_s] = 1;
}

