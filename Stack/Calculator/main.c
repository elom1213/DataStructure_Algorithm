#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"

void main(int argc, char *argv[]){
  int sum;
  char buff[256];
  if(argc < 2){
    printf("\nUnknown expression");
    exit(0);
  }
  printf("\nget input => %s,", argv[1]);
  postfix(buff, argv[1]);
  printf("\n Post fix : %s\n", buff);
  if(!is_legal(buff)){
    printf("\nExpression is not legal !..");
    exit(1);
  }
  sum = calculate_sum(buff);
  printf("\nAnswer : %d", sum);
}