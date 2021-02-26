#pragma once

node *queue[MAX];
int front, rear;

void init_queue(void){
  front = rear = 0;
}

node *put(node *k){
  if((rear + 1) % MAX == front){
    printf("\n Queue overflow....");
    return NULL;
  }
  queue[rear] = k;
  rear = ++rear % MAX;
  return k;
}

node *get(void){
  node *i;
  if(front == rear){
    printf("\n Queue underflow");
    return NULL;
  }
  i = queue[front];
  front = ++front % MAX;
  return i;
}

int is_queue_empty(void){
  return (front == rear);
}