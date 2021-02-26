#include "nodeQueue.h"

void main(void){
  int t;
  init_queue();

  printf("\nPush  3  10  32  4 80  12");
  push(3);
  push(10);
  push(32);
  push(4);
  push(80);
  push(12);
  print_q();

  t = pop();
  printf("\n Pop key : %d", t);
  print_q();

  printf("\n Clear queue");
  clear_queue();
  printf("\n Try pop");
  print_q();
  pop();
}