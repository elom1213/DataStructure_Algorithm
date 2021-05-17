#ifndef DFS_H
#define DFS_H

#include <stdlib.h>
#include <stdio.h>
#include "node.h"

#define VISIT 1

void init(node**, int*, int), insert_link(node**, int, int), dfs(node**, int*, int), print_all(node**, int), delete_all(node**, int);
node* get_node();

init(node *head[], int is_visited[], int SIZE)
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

void dfs(node *head[], int *is_visited, int cur_node)
{
	node *cur_ptr = head[cur_node];
	is_visited[cur_node] = VISIT;
	int adjNode;

	printf("visiting : %3d \n", cur_node);

	do{
		adjNode = cur_ptr->nodeNum;
		if(is_visited[adjNode] != VISIT)
			dfs(head, is_visited, adjNode);
		cur_ptr = cur_ptr->link;
	}while(cur_ptr != NULL);
}

node* get_node()
{
	node *p = (node*)malloc(sizeof(node));
	p->link = NULL;
	return p;
}

#endif // DFS_H
