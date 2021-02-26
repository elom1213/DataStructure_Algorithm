#include <stdio.h>
#include <malloc.h>

#include "parseTree.h"


void main(void){
  char post[256];
  init_stack();
  init_queue();
  init_tree();
  while(1){
    printf("\n\n Input PostFixed -> :");
    gets(post);
    if(post == NULL){
      printf("\n Program ends....");
      exit(0);
    }
    if(!is_legal(post)){
      printf("\n Expression is not legal...");
      continue;
    }
    head -> right = make_parse_tree(post);

    printf("\nPreorder traverse -> ");
    preorder_traverse(head -> right);

    printf("\nInorder traverse -> ");
    inorder_traverse(head -> right);

    printf("\nPostorder traverse -> ");
    postorder_traverse(head -> right);

    printf("\nLevelorder traverse ->");
    levelorder_traverse(head -> right);
  }
}