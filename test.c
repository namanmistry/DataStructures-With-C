#include <stdio.h>


struct pre{
  char op;
  int prec;
};

struct pre precedence[]={{'+',1},{'-',1},{'*',2},{'/',2}};
int main () {
  for(int i=0;i<=4;i++){

  printf("%c %d\n",precedence[i].op,precedence[i].prec);
  }
}