#include "List.h"
#include <stdlib.h>

node *head, *tail;

void init_list()
{
  head = (node*)malloc(sizeof(node));
  tail = (node*)malloc(sizeof(node));
  head->next = tail;
  tail->next = tail;
}

void insert_front(int k)
{
  node* new_nod = (node*)malloc(sizeof(node));
  new_nod->key = k;
  new_nod->next = head->next;
  head->next = new_nod;
}

void delete_front()
{
  node *old;
  old = head->next;
  head->next = old->next;
  free(old);
}

node *insert_after(int k, node *current)
{
  node *new_nod;
  new_nod = (node*)malloc(sizeof(node));
  new_nod->key = k;
  new_nod->next = current->next;
  current->next = new_nod;
  return new_nod;
}

int delete_next(node *current)
{
  node *next_nod;

  if (current->next == tail)
    return 0;

  next_nod = current->next;
  current->next = current->next->next; 

  free(next_nod);
  return 1;
}

// if can't find k, return the tail
node *find_node(int k)
{
  node *current;
  current = head->next;

  while (current->key != k && current != tail) 
    current = current->next;
  return current;
}

// if can't find node with k, return 0
int delete_node(int k)
{ 
  node *old, *previous;
  previous = head;
  old = previous->next;
  while (old->key != k && old != tail)
  {
    previous = previous->next;
    old = previous->next;
  }
  if (old != tail)
  {
    previous->next = old->next;
    free(old);
    return 1;
  }
  else
    return 0;
}

// previous -> new_nod : t -> next_nod : k
// if  can't find node with k, return tail
node *insert_node(int t, int k) 
{
  node *next_nod, *previous, *new_nod;
  previous = head;
  next_nod = previous->next;
  while (next_nod->key != k && next_nod != tail)
  {
    previous = previous->next;
    next_nod = previous->next;
  }
  if (next_nod != tail)
  {
    new_nod = (node*)malloc(sizeof(node));
    new_nod->key = t;
    previous->next = new_nod;
    new_nod->next = next_nod;
  }
  return previous->next;
}

node *ordered_insert(int k)
{
  node *next_nod, *previous, *new_nod;
  previous = head;
  next_nod = previous->next;
  while (next_nod->key <= k && next_nod != tail)
  {
    previous = previous->next;
    next_nod = previous->next;
  }
  new_nod = (node*)malloc(sizeof(node));
  new_nod->key = k;
  previous->next = new_nod;
  new_nod->next = next_nod; // p -> r : k -> s
  return new_nod;
}

void print_list(node *t)
{
  printf("\n");
  while(t != tail)
  {
    printf("%8d", t->key);
    t = t->next;
  }
}

node *delete_all()
{
  node *s, *t;
  t = head->next;
  while(t != tail)
  {
    s = t;
    t = t->next;
    free(s);
  }
  head -> next = tail;
  return head;
}