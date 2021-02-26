#include "Queue.h"

void main(void){
  int i;
  init_queue();

  printf("\nPush  3  10  32  4  80  12");
  push(3);
  push(10);
  push(32);
  push(4);
  push(80);
  push(12);
  print_queue();

  printf("\nPop");
  i = pop();
  print_queue();
  printf("\nPoped value is : %d", i);

  printf("\nPush 3 2 5 7");
  push(3);
  push(2);
  push(5);
  push(7);
  print_queue();

  printf("\nTry push");  
  push(1);
  print_queue();

  printf("\nInitialize queue");
  clear_queue();
  print_queue();


  printf("\nTry pop");
  pop();
}
