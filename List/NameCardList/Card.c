#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Card.h"

void init_card(void){
  head = (Card*)malloc(sizeof(Card));
  tail = (Card*)malloc(sizeof(Card));
  head->next=tail;
  tail->next=tail;
}

void insert_front(Card* input)
{
  input->next = head->next;
  head->next = input;
}

void delete_all()
{
  Card *current, *previous;
  previous = head;
  current = previous->next;
  while(current != tail)
  {
    previous = current;
    current = current->next;
    free(previous);
  }
  head->next=tail;
}

//=========================================================

void input_card(void){
  Card *current;
  current=(Card*)malloc(sizeof(Card));

  printf("\nInput namecard menu : ");
      printf("\nInput name -> ");
          scanf("%s", current->name);
      printf("\nInput corporation -> ");
          scanf("%s",current->corp);
      printf("\nInput telephone num -> ");
          scanf("%s",current->tel);

  insert_front(current);
}

int delete_card(char *fname){
  Card *card_delete;
  Card *previous;
  previous = head;
  card_delete = previous->next;
  while(strcmp(fname, card_delete->name)!=0 && card_delete!=tail){
    previous = previous->next;
    card_delete = previous->next;
  }
  if(card_delete!=tail){
    previous->next = card_delete->next;
    free(card_delete);
    printf("\n  File '%s' deleted", fname);
    return 1;
  }
  printf("\n  Can't find file '%s'", fname);
  return 0;
}

Card *search_card(char *fname){
  Card *current;
  current=head->next;
  while(strcmp(fname, current->name)!=0 && current!=tail)
    current=current->next;
  if(current!=tail){
    printf("\n  File '%s' found", fname);
    return current;
  } else {
    printf("\n  Can't find file '%s'", fname);
    return NULL;
  }
}

void load_card_from(char *fname){
  int num=0;
  FILE *fp;
  Card *current;
  if((fp=fopen(fname, "rb"))==NULL){
    printf("\n Error : %s is not exist.", fname);
    return ;
  }

  delete_all();

  while(1){
    current=(Card*)malloc(sizeof(Card));
    if(!fread(current, REC_SIZE, 1, fp)){
      free(current);
      break;
    }
    insert_front(current);
    num++;
  }
  printf("\nload %d data", num);
  fclose(fp);
}

void save_file_into(char *fname){
  FILE *fp;
  Card *source;

  if((fp=fopen(fname,"wb")) == NULL){
    printf("\n Error : Disk write failure");
    return;
  }
  
  source=head->next;
  while(source!=tail){
    fwrite(source, REC_SIZE, 1, fp);
    source = source->next;
  }
  printf("Save data");
  fclose(fp);
}


void print_header(FILE *f){
  fprintf(f, "\nName                   "
             "Corporation                      "
             "Telephone Number");
  fprintf(f,"\n---------------------  "
            "-------------------------------  "
            "----------------------");
}

void print_card(Card *c, FILE *fp){
  fprintf(fp, "\n%-20s   %-30s   %-15s", c->name, c->corp, c->tel);
}


void print_name(void){
  Card *t;
  t=head->next;
  printf("\n Current list\n");
  while(t!=tail){
    printf("\n%s", t->name);
    t=t->next;
  }
}

int select_menu(void){
  int i;
  char s[10];
  printf("\n\n NAME CARD MANAGER");
  printf("\n\n ------------------");
  printf("\n1. Input Namecard");
  printf("\n2. Delete Namecard");
  printf("\n3. Search Namecard");
  printf("\n4. Load Namecard");
  printf("\n5. Save Namecard");
  printf("\n6. List Namecard");
  printf("\n7. Print Name");
  printf("\n8. End Namecard");
  do{
    printf("\n\n : Select operation -> ");
    scanf("%s", s);
    i=atoi(s);
    printf("\nSelect %d ", i);
  } while(i<0 || i>END);
  return i;
}