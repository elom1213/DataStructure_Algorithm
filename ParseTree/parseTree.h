#include <stdlib.h>
#include <malloc.h>

#include "node.h"
#include "stack.h"
#include "queue.h"

void init_tree(void){
  head = (node*)malloc(sizeof(node));
  tail = (node*)malloc(sizeof(node));
  head -> left = tail;
  head -> right = tail;
  tail -> left = tail;
  tail -> right = tail;
}

int is_operator(int k){
  return (k == '+' || k == '-' || k == '*' || k == '/' );
}

node *make_parse_tree(char *p){
  node *t;
  while(*p){
    while(*p == ' '){
      p++;
    }
    t = (node*)malloc(sizeof(node));
    t -> key = *p;
    t -> left = tail;
    t -> right = tail;
    if(is_operator(*p)){
      t -> right = pop();
      t -> left = pop();
    }
    push(t);
    p++;
  }
  return pop();
}

int is_legal(char *s){
  int f = 0;
  while(*s){
    while(*s == ' '){
      s++;
    }
    if(is_operator(*s)){
      f--;
    } else {
      f++;
    }
    if(f < 1){
      break;
    }
    s++;
  }
  return(f == 1);
}

void visit(node *p){
  printf("%c  ", p->key);
}

void preorder_traverse(node *t){
  if(t != tail){
    visit(t);
    preorder_traverse(t->left);
    preorder_traverse(t->right);
  }
}
void inorder_traverse(node *t){
  if(t != tail){
    inorder_traverse(t->left);
    visit(t);
    inorder_traverse(t->right);
  }
}
void postorder_traverse(node *t){
  if(t != tail){
    postorder_traverse(t->left);
    postorder_traverse(t->right);
    visit(t);
  }
}
void levelorder_traverse(node *t){
  put(t);
  while(!is_queue_empty()){
    t = get();
    visit(t);
    if(t -> left != tail){
      put(t -> left);
    }
    if(t -> right != tail){
      put(t -> right);
    }
  }
}