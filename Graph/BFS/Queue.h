#ifndef _QUEUE
#define _QUEUE

#include <stdlib.h>
#include <stdio.h>

typedef struct _queue_node
{
   int data;
   struct _queue_node *next;
} queue_node;

queue_node *front, *rear;

void init_queue()
{
    rear = front = NULL;
}

int is_empty()
{
    return front == NULL;
}

void enqueue(int data)
{
    queue_node *new_node = (queue_node*)malloc(sizeof(queue_node));
    new_node->data = data;

    if(is_empty())
	front = rear = new_node;
    else
    {
	rear->next = new_node;
        rear = new_node;
    }
}

int dequeue()
{
    if(!is_empty())
    {
	int front_data = front->data;
	queue_node *tmp = front;
	front = front->next;
	free(tmp);
	return front_data;
    }else
    {
	printf("queue is empty\n");
	return 0;
    }
}

void print_queue()
{
    queue_node *ptr = front;
    while(ptr != NULL)
    {
	printf("%d <- ", ptr->data);
	ptr = ptr->next;
    }
    printf("\n");
}

void delete_queue()
{
    while(!is_empty())
	dequeue();
}
#endif // _QUEUE
