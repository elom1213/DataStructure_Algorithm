#include "DList.h"
#include <stdio.h>
#include <stdlib.h>

dnode *head, *tail;

void init_dlist(void){
  head=(dnode*)malloc(sizeof(dnode));
  tail=(dnode*)malloc(sizeof(dnode));
  head->next=tail;
  head->prev=head;
  tail->next=tail;
  tail->prev=head;
}

dnode *insert_after(int k, dnode *next_nod){
  dnode *new_nod;
  if(next_nod==head)
    return NULL;
  new_nod=(dnode*)malloc(sizeof(dnode));
  new_nod->key=k;
  next_nod->prev->next=new_nod;
  new_nod->prev=next_nod->prev;
  next_nod->prev=new_nod;
  new_nod->next=next_nod;
  return new_nod;
}

dnode *find_dnode(int k){
  dnode *current;
  current=head->next;
  while(current->key != k && current != tail)
    current=current->next;
  return current;
}

int delete_dnode(dnode *current){
  if(current==head || current==tail)
    return 0;
  current->prev->next=current->next;
  current->next->prev=current->prev;
  free(current);
  return 1;
}

int delete_dnode_keyof(int k){
  dnode *current;
  current = find_dnode(k);
  if(current!=tail){
    current->prev->next=current->next;
    current->next->prev=current->prev;
    free(current);
    return 1;
  }
  return 0;
}

// 
dnode *insert_node(int k, int t){
  dnode *next_nod;
  dnode *new_nod = NULL;
  next_nod = find_dnode(t);
  if(next_nod!=tail){
    new_nod = (dnode*)malloc(sizeof(dnode));
    new_nod->key=k;
    next_nod->prev->next=new_nod;
    new_nod->prev=next_nod->prev;
    new_nod->next=next_nod;
    next_nod->prev=new_nod;
  }
  return new_nod;
}

dnode *ordered_insert(int k){
  dnode *new_nod;
  dnode *next_nod = head->next;
  while(next_nod!=tail && next_nod->key <= k)
    next_nod=next_nod->next;
  new_nod=(dnode*)malloc(sizeof(dnode));
  new_nod->key=k;
  next_nod->prev->next=new_nod;
  new_nod->prev=next_nod->prev;
  new_nod->next=next_nod;
  next_nod->prev=new_nod;
  return new_nod;
}

void print_list(void){
  printf("\n");
  dnode *t=head->next;
  while(t!=tail){
    printf("%5d", t->key);
    t=t->next;
  }
}