#include "DList.h"
#include <stdio.h>

void main(void){
  dnode *t;
  init_dlist();
  ordered_insert(40);
  ordered_insert(3);
  ordered_insert(16);
  ordered_insert(8);
  ordered_insert(4);
  print_list();

  t = find_dnode(4);
  insert_after(35, t);
  printf("\nInsert 35 before 4");
  print_list();
  delete_dnode(t);
  printf("\nDelete node 4");
  print_list();
  insert_node(11,40);
  printf("\nInsert 11 before 40");
  print_list();
}