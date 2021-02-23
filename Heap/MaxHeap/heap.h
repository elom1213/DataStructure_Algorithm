#pragma once

#define MAX_HEAP_SIZE   200

typedef struct _heap 
{
  int heap[MAX_HEAP_SIZE];
  unsigned int size;
} heap;

// create, init heap
heap* create_heap();
void init_heap(heap*);

// build max heap
void build_max_heap(heap*, int arr[], const int siz);
    // sub routine
    void max_heap_increase(heap*, int key);
    void heap_insert_key(heap*, int idx, int key);

// sorting 
void heap_sort(heap*, int[], const int siz);
    // sub routine
    int heap_extract_max(heap*);
    void max_heapify(heap*, int idx);
