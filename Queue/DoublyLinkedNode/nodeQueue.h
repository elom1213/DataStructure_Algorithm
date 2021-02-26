#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode {
  int key;
  struct _dnode *next;
  struct _dnode *prev;
} dnode ;

dnode *head, *tail;

void init_queue(void){
  head = (dnode*)malloc(sizeof(dnode));
  tail = (dnode*)malloc(sizeof(dnode));
  head -> next = tail;
  head -> prev = head;
  tail -> next = tail;
  tail -> prev = head;
}

int push(int k){
  dnode *newNode;
  if((newNode = (dnode*)malloc(sizeof(dnode))) == NULL){
    printf("\n  Out of memory");
    return -1;
  }
  newNode->key = k;
  tail -> prev -> next = newNode;
  newNode -> prev = tail -> prev;
  tail -> prev = newNode;
  newNode -> next = tail;
  return k;
}

int pop(){
  dnode *popNode;
  int i;
  popNode = head->next;
  if(popNode==tail){
    printf("\n Queue underflow");
    return -1;
  }
  i = popNode->key;
  head -> next = popNode -> next;
  popNode->next->prev = head;
  free(popNode);
  return i;
}

void clear_queue(void){
  dnode *t, *s;
  t=head->next;
  while(t!=tail){
    s = t;
    t = t->next;
    free(s);
  }
  head -> next = tail;
  tail -> prev = head;
}

void print_q(void){
  dnode *t;
  t=head->next;
  printf("\n Print queue  Front ----> rear\n");
  while(t!=tail){
    printf("%-5d", t->key);
    t = t->next;
  }
}