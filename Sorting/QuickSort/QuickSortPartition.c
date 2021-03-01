#include <stdio.h>

void swap(int* a, int* b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void printArr(int arr_[], int max_)
{
  int i;
  printf("\n\n");
  for(i=0; i<max_; i++)
    printf("%4d", arr_[i]);
}

int partition(int* arr, int be, int end)
{
  int i, j, pivot;
  pivot = arr[end];
  j = be - 1;
  i = be - 1;
  while(++j<end)
    if(arr[j]<=pivot)
      swap(&arr[++i], &arr[j]);
  swap(&arr[++i], &arr[end]);
  return i;
}

void quickSort(int* arr, int be, int end)
{
  int pivotIdx;
  if(be < end)
  {
    pivotIdx = partition(arr, be, end);
    quickSort(arr, be, pivotIdx-1);
    quickSort(arr, pivotIdx+1, end);
    printArr(arr, 10);
  }
}

// CLRS 7.1 Quicksort
int main(void) {
  int arr[] = {21,23,54,3,90,7,79,40,1,26};
  int leng = sizeof(arr)/sizeof(int);
  printArr(arr, leng);
  quickSort(arr, 0, leng-1);
  printArr(arr, leng);
  return 0;
}