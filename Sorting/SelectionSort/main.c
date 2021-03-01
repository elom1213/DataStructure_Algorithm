#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELE_NUM 10
int rec[ELE_NUM] = {2,66,4,0,8,5,57,1,27,23};

int intComp(const void* i, const void* j){
  return (*(int*)i - *(int*)j);
}

int strComp(const void* i, const void* j){
  return (*(int*)i - *(int*)j);
}

void printRec(int leng_, int rec_[]){
  int k;
  for(k = 0; k < leng_; k++){
    printf("%d, ", rec_[k]);
  }
}

void select_sort(void *base, size_t numelem, size_t width, int (*fcmp)(const void*, const void*) )
{
  void *min;
  int minInd, i, j;
  min = malloc(width);
  for(i = 0; i < numelem - 1 ; i ++ )
  {
    minInd = i;
    memcpy(min, (char*)base + i*width, width);
    for(j = i + 1; j < numelem; j ++)
    {
      if(fcmp(min, (char*)base + j*width) > 0)
      {
        memcpy(min, (char*)base + j*width, width);
        minInd = j;
      }
    }
    if(minInd != i)   // swap base[i] and base[j]
    {
      memcpy((char*)base + minInd*width, (char*)base + i*width, width); 
      memcpy((char*)base + i*width, min, width); 
    }
    printf("\nsorting => ");
    printRec(ELE_NUM, base);
  }
  free(min);
}

/**
 * selection sort swaps elements n times for each step in worst case
 * it takes n(n-1)/2 comparison
*/

int main(void){
  printf("\nbefore => ");
  printRec(ELE_NUM, rec);
  select_sort(rec, ELE_NUM, sizeof(int), intComp);
  printf("\nafter => ");
  printRec(ELE_NUM, rec);
  return 0;
}