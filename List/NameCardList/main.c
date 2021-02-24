#include <stdio.h>
#include "Card.h"

/*
   NAME CARD MANAGER
  
   ------------------   
  1. Input Namecard     
  2. Delete Namecard    
  3. Search Namecard    
  4. Load Namecard      
  5. Save Namecard      
  6. List Namecard      
  7. Print Name
  8. End Namecard  

*/


void main(void){
  char *fname = "Card_Data\\NameCard.dat";
  char name[NAME_SIZE];
  int i;
  Card *t;
  
  init_card();
  
  while((i=select_menu()) != END){
    switch(i){
    case 1 :
        input_card();
        break;
    case 2 :
      // delets
        printf("\n  Input name to delete -> ");
        scanf("%s", name);
        if(!delete_card(name))
          printf("\n    Can't find that name");
        break;
    case 3 :
      // search
        printf("\n  Input name to search -> ");
        scanf("%s", name);
        t=search_card(name);
        if(t==NULL){
          printf("\n    Can't find that name");
          break;
        }
        print_header(stdout);
        print_card(t, stdout);
        break;
    case 4 :
        load_card_from(fname);
        break;
    case 5 :
        save_file_into(fname);
        break;
    case 6 :
      // show List
        t=head->next;
        print_header(stdout);
        while(t!=tail){
          print_card(t, stdout);
          t=t->next;
        }
        break;
    case 7 :
        print_name();
        break;
    }
  }
  printf("\n\nProgram ends...");
}