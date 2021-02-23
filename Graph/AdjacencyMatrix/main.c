#include <stdio.h>

#define _BUTTERFLY
#include "Graph.h"

void create_butterfly_network(GraphType*, int);
void insert_butterfly_edge(GraphType*, int, int);
void print_adj_mat(GraphType*);

// Mathematics for Computer Science MIT 6.042J
// making butterfly network using adjacency matrix
int main(void) {
  GraphType mygraph;
  init(&mygraph);

#ifdef _BUTTERFLY
  set_total_node_num(&mygraph, MAXSIZ);
  create_butterfly_network(&mygraph, INPUT_LEVEL);
#else
  set_total_node_num(&mygraph, 4);

  set_edge(&mygraph, 0, 1);
  set_edge(&mygraph, 0, 2);
  set_edge(&mygraph, 1, 3);
  /*
    0 1 1 0
    1 0 0 1
    1 0 0 0
    0 1 0 0
  */
#endif
  print_adj_mat(&mygraph);
}

// create butterfly network!
#ifdef _BUTTERFLY
void create_butterfly_network(GraphType* graph, int input_level)
{
  for(int i = 0; i < input_level ; i++)
    insert_butterfly_edge(graph, i, 0);
}

void insert_butterfly_edge(GraphType* graph, int _s, int _lev)
{
  if((_s>>LEVEL)>=LEVEL) return;
  int next_lev = (_lev+1)<<(LEVEL);
  int flip_bit = INPUT_LEVEL>>(_lev+1);
  int dist = next_lev|(_s%(INPUT_LEVEL));
  set_edge(graph, _s, dist);
  set_edge(graph, _s, FLIP(dist, flip_bit));
  insert_butterfly_edge(graph, dist, _lev+1);
  insert_butterfly_edge(graph, FLIP(dist, flip_bit), _lev+1);
}
#endif

void print_adj_mat(GraphType* graph)
{
  int graph_siz = graph->total_node_num;
  for(int j=0; j<graph_siz; j++, putchar('\n'))
    for(int i=0; i<graph_siz; printf("%2d",graph->adj_mat[j][i++]));
}


