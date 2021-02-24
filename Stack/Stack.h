#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top;

void init_stack(){
  top = -1;
}

int push(int t){
  if(top >= MAX -1){
    printf("\n Stack Overflow...");
    exit(1);
  }
  stack[++top] = t;
  return t;
}

int pop(void){
  if(top < 0){
    printf("\n Stack Underflow...");
    exit(1);
  }
  return stack[top--];
}

int get_stack_top(){
  return (top < 0) ? -1 : stack[top];
}

int is_stack_empty(){
  return (top < 0);
}

void print_stack(){
  int i;
  printf("\n Stack contents : Top ---> Bottom \n");
  for(i = top; i >= 0; i--){
    printf("%-6d", stack[i]);
  }
  printf("\n");
}