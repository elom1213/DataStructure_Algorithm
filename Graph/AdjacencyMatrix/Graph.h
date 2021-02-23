#pragma once

#ifdef _BUTTERFLY
#define LEVEL 2
#define MAXSIZ ((1<<LEVEL)*(LEVEL+1))
#define INPUT_LEVEL 1<<LEVEL
#define FLIP(source, bit) (source^bit)
#else
#define MAXSIZ 100
#endif

typedef struct _GraphType
{
  int total_node_num;
  int adj_mat[MAXSIZ][MAXSIZ];
} GraphType;

void init(GraphType*);
void set_total_node_num(GraphType*, int nodenum);
void set_edge(GraphType*, int src, int dist);
