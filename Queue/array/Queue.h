#include <stdio.h>

#define MAX 10

int queue[MAX];
int front, rear;

void init_queue(void){
  front = rear = 0;
}

void clear_queue(void){
  front = rear;
}

int push(int k){
  if((rear +1) % MAX == front){
    printf("\n Error : queue overflow ...");
    return -1;
  }
  queue[rear] = k;
  rear = ++rear % MAX ;
  return k;
}

int pop(void){
  int i;
  if(front == rear){
    printf("\n Error : queue underflow ...");
    return -1;
  }
  i = queue[front];
  front = ++front % MAX;
  return i;
}

void print_queue(void){
  int i;
  printf("\n Queue contents : Front ---> Rear\n");
  for(i = front ; i != rear ; i = ++i % MAX){
    printf("%-5d", queue[i]);
  }
}