#include <stdio.h>
#include <string.h>
#include "Calculator.h"
#include "../Stack.h"


int is_operator(int exp){
  return (exp == '+' || exp == '-' || exp == '*' || exp == '/');
}

int precedence(int op){
  if(op == '(') return 0;
  if(op == '+' || op == '-') return 1;
  if(op == '*' || op == '/') return 2;
  else return 3;
}

void postfix(char *dst, char *src){
  char c;
  init_stack();
  while(*src){
    if(*src == '('){
      push(*src);
      src++;
    }
    else if(*src == ')'){
      while(get_stack_top() != '('){
        *dst ++ = pop();
        *dst ++ = ' ';
      }
      pop();
      src++;
    }
    else if(is_operator(*src)){
      while(!is_stack_empty() && precedence(get_stack_top()) >= precedence(*src)){
        *dst++ = pop();
        *dst++ = ' ';
      }
      push(*src);
      src++;
    }
    else if(*src >= '0' && *src <= '9'){
      do{
        *dst++ = *src++;
      }while(*src >= '0' && *src <= '9');
      *dst++= ' ';
    }
    else
    {
      src++;
    }
  }
  while(!is_stack_empty()){
    *dst++ = pop();
    *dst++ = ' ';
  }
  dst--;
  *dst = 0;
}

int is_legal(char *s){
  int f = 0;
  while(*s){
    while(*s == ' '){
      s++;
    }
    if(is_operator(*s)){
      f--;
    }else{
      f++;
      while(*s != ' '){
        s++;
      }
    }
    if(f < 1) break;
    s++;
  }
  return(f == 1);
}

int calculate_sum(char *p){
  int s;
  init_stack();
  while(*p){
    if(*p >= '0' && *p <= '9'){
      s = 0;
      do{
        s = s * 10 + (p[0] - '0');
        p++;
      }while(*p >= '0' && *p <= '9');
      push(s);
      printf("\nPop : Num\nCurrent value is : %d\n", stack[top]);
    }
    else if(*p == '+'){
      push(pop() + pop());
      p++;
      printf("\nPop : +\nCurrent value is : %d\n", stack[top]);
    }
    else if(*p == '-'){
      s = pop();
      push(pop() - s);
      p++;
      printf("\nPop : -\nCurrent value is : %d\n", stack[top]);
    }
    else if(*p == '*'){
      push(pop() * pop());
      p++;
      printf("\nPop : *\nCurrent value is : %d\n", stack[top]);
    }
    else if(*p == '/'){
      s = pop();
      push(pop() / s);
      p++;
      printf("\nPop : /\nCurrent value is : %d\n", stack[top]);
    }
    else
      p++;
  }
  return pop();
}
