#pragma once

#include <stdio.h>
#include "node.h"

#define MAX 100

node *stack[MAX];
int top;

void init_stack(void){
  top = -1;
}

node *push(node *k){
  if(top >= MAX){
    printf("\n Stack overflow... sad");
    return NULL;
  }
  stack[++top] = k;
  return k;
}

node *pop(void){
  if(top < 0){
    printf("\n Stack underflow...");
    return NULL;
  }
 return stack[top--];
}

int is_stack_empty(void){
  return (top == -1);
}