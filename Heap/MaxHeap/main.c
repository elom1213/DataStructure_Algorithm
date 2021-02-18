#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include "heap.h"

#define ARRAY_SIZE      15

void put_random_num(int*);
void print_heap(heap* _h);

// CLRS 2.6 Heapsort
int main(void) {
  //set up
  heap* myheap ;
  myheap = create_heap();
  init_heap(myheap);

  /**
   * create arbitrary array. with heap data structure,
   * we'll build max_heap. 
   * it also gives priority queue operation
  */

  int arr[ARRAY_SIZE];
  put_random_num(arr);

  for(int i=0; i<ARRAY_SIZE; i++) printf("%d\t", arr[i]);
  putchar('\n');  

  // build heap
  build_max_heap(myheap, arr, ARRAY_SIZE);
  print_heap(myheap);

  // sort array
  heap_sort(myheap, arr);
  putchar('\n');
  for(int i=0; i<ARRAY_SIZE; i++) printf("%d\t", arr[i]);

  free(myheap);
}

void put_random_num(int* _arr)
{
  srand((size_t)time(NULL));
  for(int i=0; i < ARRAY_SIZE ; _arr[i++] = rand()%100);
}
