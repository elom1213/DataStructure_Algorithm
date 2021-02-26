#pragma once

typedef struct _node{
  int key;
  struct _node *left;
  struct _node *right;
} node;

node *head, *tail;