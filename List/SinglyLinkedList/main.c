#include "List.h"
#include <stdio.h>

void main(void)
{
  node *t;

  init_list();
  insert_front(10);
  insert_front(1);
  insert_front(6);
  insert_front(15);

  printf("\nInitial linked list");
  print_list(head->next);

  printf("\nFinding 6 is %ssuccessful", find_node(6) == tail ? "un" : "");
  printf("\nFinding 3 is %ssuccessful", find_node(3) == tail ? "un" : ""); // err

  t = find_node(6);
  printf("\nInserting 8 after 6");
  insert_after(8, t);
  print_list(head->next);

  t=find_node(1);
  printf("\nDelete next 1");
  delete_next(t);
  print_list(head->next);
   
  printf("\nDelete node 3");
  if(!delete_node(3)){
    printf("\nDeleting 3 is Unsuccessful!!");
  }
  delete_all();
  print_list(head->next);
}