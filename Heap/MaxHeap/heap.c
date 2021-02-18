#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

// print
void print_heap(heap* _h)
{
  int i = 0b01;
  int s = 0b10;
  //===============================================prob
  int n = _h->size;
  for(; i <= n ; s<<=1, putchar('\n')) 
    for(; i < s; printf("\t%d", _h->heap[i++]));
}

// create, init
heap* create_heap()
{
  return (heap*)malloc(sizeof(heap));
}

void init_heap(heap* _h)
{
  memset(_h->heap, 0, sizeof(MAX_HEAP_SIZE));
  _h->heap[0] = SENTINEL;
  _h->size = 0;
}

// build
void build_max_heap(heap* _h, int _arr[], const int arr_siz)
{
  for(int i = 0; i < arr_siz ; i++)
    max_heap_increase(_h, _arr[i]);
};

void max_heap_increase(heap* _h, int _key)
{
  _h->size++;
  heap_insert_key(_h, _h->size, _key);
};

void heap_insert_key(heap* _h, int _idx, int _key)
{
  _h->heap[_idx] = _key;
  while(_h->heap[PARENT(_idx)] < _h->heap[_idx])
  {
    SWAP(_h->heap[PARENT(_idx)], _h->heap[_idx]);
    _idx = PARENT(_idx);
  }
};

// sorting
void heap_sort(heap* _h, int _arr[])
{
  //===============================================prob
  for(int max, i=1; i <= _h->size; i++)
  {
    max = heap_extract_max(_h);
    _arr[i-1] = max;

    // print for each extraction
    putchar('\n');
    print_heap(_h);
  }
}

int heap_extract_max(heap* _h)
{
  int max = _h->heap[1];
  _h->heap[1] = 0;
  SWAP(_h->heap[1], _h->heap[_h->size]);
  _h->size--;
  max_heapify(_h, 1);
  return max;
}

void max_heapify(heap* _h, int idx)
{
  int largest_child_idx = idx;
  if(_h->heap[idx] < _h->heap[LEFT(idx)])
    largest_child_idx = LEFT(idx);
  if(_h->heap[largest_child_idx] < _h->heap[RIGHT(idx)])
    largest_child_idx = RIGHT(idx);
  if (largest_child_idx != idx)
  {
    SWAP(_h->heap[idx], _h->heap[largest_child_idx]);
    max_heapify(_h, largest_child_idx);
  }
}