#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int key;
  struct _node *next;
} node;

node *head, *tail;

void init_list();

void insert_front(int k);
void delete_front();

node *insert_after(int k, node *t);
int delete_next(node *current);

node *find_node(int k);
int delete_node(int k);

node *insert_node(int t, int k);
node *ordered_insert(int k);

void print_list(node *t);

node *delete_all();

#endif // __LIST_H