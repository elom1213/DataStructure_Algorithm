#pragma once

#define MAX_HEAP_SIZE   200
#define SENTINEL        0x7fffffff

#define PARENT(i)       (i>>1)
#define LEFT(i)         (i<<1)
#define RIGHT(i)        ((i<<1)|1)
#define SWAP(x, y)      {x ^= y ; y ^= x ; x ^= y;}

typedef struct _heap 
{
  int heap[MAX_HEAP_SIZE];
  unsigned int size;
} heap;

// create, init heap
heap* create_heap();
void init_heap(heap*);

// build max heap
void build_max_heap(heap*, int[], const int);
    // sub routine
    void max_heap_increase(heap*, int);
    void heap_insert_key(heap*, int, int);

// sorting 
void heap_sort(heap*, int[]);
    // sub routine
    int heap_extract_max(heap*);
    void max_heapify(heap*, int);
