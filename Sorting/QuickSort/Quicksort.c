#include <stdio.h>

void printArr(int arr_[], int max_)
{
  int i;
  printf("\n\n");
  for(i=0; i<max_; i++){
    printf("%2d", arr_[i]);
  }
}

void quickSort(int arr_[], int arrSiz_)
{
  int i, j;
  int tmp, pivot;
  pivot = arr_[arrSiz_-1];
  i = -1;
  j = arrSiz_ - 1;
  if(arrSiz_ > 1)
  {
    while(1)
    {
      while(arr_[++i] < pivot);
      while(arr_[--j] > pivot);
      if(i >= j) break;
      tmp = arr_[i];
      arr_[i] = arr_[j];
      arr_[j] = tmp;
    }
    tmp = arr_[i];
    arr_[i] = arr_[arrSiz_-1];
    arr_[arrSiz_-1] = tmp;
    printArr(arr_, arrSiz_);

    quickSort(arr_, i);
    quickSort(arr_ + i + 1, arrSiz_ - i - 1);
  }
}

int arr[] = {21,23,54,3,90,7,79,40,1,26};

int main(void) {
  int leng = sizeof(arr)/sizeof(int);
  printArr(arr, leng);
  quickSort(arr, leng);
  printArr(arr, leng);
  return 0;
}