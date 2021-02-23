#ifndef __DLIST_H
#define __DLIST_H

typedef struct _dnode{
  int key;
  struct _dnode *prev;
  struct _dnode *next;
} dnode;

void init_dlist();

dnode *insert_after(int k, dnode *next_nod);
dnode *find_dnode(int k);

int delete_dnode(dnode *current);
int delete_dnode_keyof(int k);

dnode *insert_node(int k, int t);
dnode *ordered_insert(int k);

void print_list(void);

#endif