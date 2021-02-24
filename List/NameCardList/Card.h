#pragma once

#include <stdio.h>

#define END 8
#define NAME_SIZE 21
#define CORP_SIZE 31
#define TEL_SIZE 16
#define REC_SIZE (NAME_SIZE+CORP_SIZE+TEL_SIZE)

typedef struct _Card{
  char name[NAME_SIZE];
  char corp[CORP_SIZE];
  char tel[TEL_SIZE];
  struct _Card *next;
} Card;

Card *head, *tail;

void init_card();

void input_card();
int delete_card(char *fname);
Card *search_card(char *fname);
void load_card_from(char *fname);
void save_file_into(char *fname);
void print_header(FILE *f);
void print_card(Card *c, FILE *fp);
void print_name(void);

int select_menu(void);

void insert_front(Card* input);
void delete_all();