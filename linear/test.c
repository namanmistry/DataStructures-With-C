#include<stdio.h>
#include<conio.h>
char input[10];
void main(){
printf("Enter an expression: \n");
scanf("%s",&input);

reverse();
printf("Your Answer Is: %s\n",input);

}


void reverse(){
    int m=0;
    int n=0;
    char c;
    while(input[m]!='\0'){
      m++;
      printf("I am here 2\n");
    }
    while(n<=m){
      printf("I am here\n");
      
        
        c=input[n];
        input[n]=input[m];
        input[m]=c;
        m--;
        n++;
        
    }

}