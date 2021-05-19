#ifndef BFS_H
#define BFS_H

#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "Queue.h"

#define VISIT 1

void init(node**, int*, int), insert_link(node**, int, int), bfs(node**, int*, int), print_all(node**, int), delete_all(node**, int);
node* get_node();

void init(node *head[], int is_visited[], int SIZE)
{
	for(int i=0; i<SIZE;i++)
	{
		head[i] = NULL;
		is_visited[i] = 0;
	}
}

void insert_link(node** head, int v1, int v2)
{
	node *new_node =  get_node();
	new_node->nodeNum = v2;
	new_node->link = head[v1];
	head[v1] = new_node;
}

void print_all(node *head[], int SIZE)
{
	node *p;
	for(int i=0; i<SIZE;i++)
	{
		p = head[i];
		printf("%2d List : ", i);
		while(p != NULL)
		{
			printf("%3d", p->nodeNum);
			p = p->link;
		}
		putchar('\n');
	}
}


void delete_all(node *head[], int SIZE)
{
	node *cur, *prev;
	for(int i=0;i<SIZE;i++)
	{
		prev = head[i];
		cur = prev->link;
		free(prev);
		while(cur != NULL)
		{
			prev = cur;
			cur = cur->link;
			free(prev);
		}
	}
}

void bfs(node *head[], int *is_visited, int start_node)
{
	node *adj_node;
	int cur_node;
	is_visited[start_node] = VISIT;
	enqueue(start_node);

	while(!is_empty())
	{
	    cur_node = dequeue();
	    printf("visiting : %3d \n", cur_node);
	    adj_node = head[cur_node];

	    while(adj_node != NULL)
	    {
		if(is_visited[adj_node->nodeNum] != VISIT)
		{
		    is_visited[adj_node->nodeNum] = VISIT;
		    enqueue(adj_node->nodeNum);
		}
		adj_node = adj_node->link;
	    }
	    print_queue();
	};
}

node* get_node()
{
	node *p = (node*)malloc(sizeof(node));
	p->link = NULL;
	return p;
}

#endif // BFS_H
