#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0
#define START 0
#define SIZE 5

int visited[SIZE];

/*
 * given a graph
 *
 * 			0
 *		      /   \
 *		     1    2
 *	   	     / \ / 
 *	   	    3   4
 *
 * operate DFS form START vertex
 */

int main()
{
	int v1, v2, SW;
	int is_visited[SIZE] = {0};
	node *head[SIZE];
	char opcode;
	FILE *fp;

	init(head, is_visited, SIZE);
	SW = ON;
	while(SW)
	{
		printf("Insert opcode\n");
		printf("I : Insert, T : Traversal, P : Print, Q : Quit\n=>" );
		scanf(" %s", &opcode);
		printf("\nOpcode => %c\n", opcode);
		switch(opcode)
		{
			case'I':
				if((fp = fopen("graph.dat", "r")) != NULL)
				{
					while(fscanf(fp, "%d %d \n", &v1, &v2) != EOF)
					{
						printf("Insert Data => %d %d\n", v1, v2);
						insert_link(head, v1, v2);
						insert_link(head, v2, v1);
					}
				}else
			       	{
					fprintf(stderr, "fopen fail\n");
					exit(1);
				}
			break;
			case'T':
				dfs(head, is_visited, START);
				memset(is_visited, 0, SIZE*sizeof(int));	
			break;
			case'P':
				print_all(head, SIZE);
			break;
			case'Q':
				delete_all(head, SIZE);
				print_all(head, SIZE);
				SW = OFF;
			break;
			default:
				printf("error unknown opcode\n");
			break;
		}
	}
}
