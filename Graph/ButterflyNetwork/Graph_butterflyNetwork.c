#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEVEL 1
#define INPUT 1<<LEVEL
#define MAXSIZ ((1<<LEVEL)*(LEVEL+1))
#define FLIP(source, bit) (source^bit)

typedef struct _GraphType
{
  int total_node_num;
  int adj_mat[MAXSIZ][MAXSIZ];
} GraphType;

void init(GraphType*);

// set
void set_total_node_num(GraphType*, int);
void set_edge(GraphType*, int, int);

void insert_butterfly_edge(GraphType*, int, int);

// UI
void print_adj_mat(GraphType*);

// main
int main(void) {
  GraphType mygraph;
  init(&mygraph);


  // can make butterfly graph

  // set_total_node_num(&mygraph, MAXSIZ);

  // for(int i = 0; i < INPUT ; i++)
  //   insert_butterfly_edge(&mygraph, i, 0);

  set_total_node_num(&mygraph, 4);

  set_edge(&mygraph, 0, 1);
  set_edge(&mygraph, 0, 2);
  set_edge(&mygraph, 1, 3);

  print_adj_mat(&mygraph);
  /*
    0 1 1 0
    1 0 0 1
    1 0 0 0
    0 1 0 0
  */
}

void init(GraphType *graph)
{
  graph->total_node_num = 0;
  memset(graph->adj_mat, 0, sizeof(graph->adj_mat));
};


// insert operator
void set_total_node_num(GraphType* graph, int nodenum)
{
  if(MAXSIZ < nodenum)
  {
    fprintf(stderr, "invalid max size\n");
    exit(0);
  }
  graph->total_node_num = nodenum;
}

void set_edge(GraphType* graph, int _s, int _v)
{
  if(_s > graph->total_node_num || _v > graph->total_node_num)
  {
    fprintf(stderr, "invalid input node\n");
    exit(0);
  }
  graph->adj_mat[_s][_v] = graph->adj_mat[_v][_s] = 1;
}


// make butterfly network!
void insert_butterfly_edge(GraphType* graph, int _s, int _lev)
{
  if((_s>>LEVEL)>=LEVEL) return;
  int next_lev = (_lev+1)<<(LEVEL);
  int flip_bit = INPUT>>(_lev+1);
  int dist = next_lev|(_s%(INPUT));
  set_edge(graph, _s, dist);
  set_edge(graph, _s, FLIP(dist, flip_bit));
  insert_butterfly_edge(graph, dist, _lev+1);
  insert_butterfly_edge(graph, FLIP(dist, flip_bit), _lev+1);
}

// UI
void print_adj_mat(GraphType* graph)
{
  int graph_siz = graph->total_node_num;
  for(int j=0; j<graph_siz; j++, putchar('\n'))
    for(int i=0; i<graph_siz; printf("%2d",graph->adj_mat[j][i++]));
}


/*

level 1

 0 0 1 1
 0 0 1 1
 1 1 0 0
 1 1 0 0

level 2

 0 0 0 0  1 0 1 0  0 0 0 0
 0 0 0 0  0 1 0 1  0 0 0 0
 0 0 0 0  1 0 1 0  0 0 0 0
 0 0 0 0  0 1 0 1  0 0 0 0
 
 1 0 1 0  0 0 0 0  1 1 0 0
 0 1 0 1  0 0 0 0  1 1 0 0
 1 0 1 0  0 0 0 0  0 0 1 1
 0 1 0 1  0 0 0 0  0 0 1 1
 
 0 0 0 0  1 1 0 0  0 0 0 0
 0 0 0 0  1 1 0 0  0 0 0 0
 0 0 0 0  0 0 1 1  0 0 0 0
 0 0 0 0  0 0 1 1  0 0 0 0

level 3

 0 0 0 0 0 0 0 0  1 0 0 0 1 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 1 0 0 0 1 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 1 0 0 0 1 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 1 0 0 0 1  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  1 0 0 0 1 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 1 0 0 0 1 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 1 0 0 0 1 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 1 0 0 0 1  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0

 1 0 0 0 1 0 0 0  0 0 0 0 0 0 0 0  1 0 1 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 1 0 0 0 1 0 0  0 0 0 0 0 0 0 0  0 1 0 1 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 1 0 0 0 1 0  0 0 0 0 0 0 0 0  1 0 1 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 1 0 0 0 1  0 0 0 0 0 0 0 0  0 1 0 1 0 0 0 0  0 0 0 0 0 0 0 0
 1 0 0 0 1 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 1 0 1 0  0 0 0 0 0 0 0 0
 0 1 0 0 0 1 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 1 0 1  0 0 0 0 0 0 0 0
 0 0 1 0 0 0 1 0  0 0 0 0 0 0 0 0  0 0 0 0 1 0 1 0  0 0 0 0 0 0 0 0
 0 0 0 1 0 0 0 1  0 0 0 0 0 0 0 0  0 0 0 0 0 1 0 1  0 0 0 0 0 0 0 0

 0 0 0 0 0 0 0 0  1 0 1 0 0 0 0 0  0 0 0 0 0 0 0 0  1 1 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 1 0 1 0 0 0 0  0 0 0 0 0 0 0 0  1 1 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  1 0 1 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 1 1 0 0 0 0
 0 0 0 0 0 0 0 0  0 1 0 1 0 0 0 0  0 0 0 0 0 0 0 0  0 0 1 1 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 1 0 1 0  0 0 0 0 0 0 0 0  0 0 0 0 1 1 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 1 0 1  0 0 0 0 0 0 0 0  0 0 0 0 1 1 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 1 0 1 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 1 1
 0 0 0 0 0 0 0 0  0 0 0 0 0 1 0 1  0 0 0 0 0 0 0 0  0 0 0 0 0 0 1 1

 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  1 1 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  1 1 0 0 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 1 1 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 1 1 0 0 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 1 1 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 1 1 0 0  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 1 1  0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 1 1  0 0 0 0 0 0 0 0
 */