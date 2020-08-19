#include<stdio.h>
#include<stdlib.h>


//Declarations Of Global Variables
char stack[10],input[10],output[10];
char c;
int top=-1,j=0;

struct pre{
    char op;
    int prec;
}

precedence[]={{'+',1},{'-',1},{'*',2},{'/',2}};

int m,n;

void main(){
//Scanning The expression
printf("Enter The Expression: \n");
scanf("%s",&input);


int p=0,q=4;
// printf("%d\n",q);
while(p<=q)
{
    int temp;
    temp=input[q];
    input[q]=input[p];
    input[p]=temp;
    p++;
    q--;
    // printf("naman\n");
}
// for(int i=0;input[i]!='\0';i++){
//     printf("%c",input[i]);

// }

for(int i=0;input[i]!='\0';i++){
    c=input[i];
    
    switch(c){
        case '+':plus();
        break;
        case '-':minus();
        break;
        case '*':mul();
        break;
        case '/':division();
        break;
        case '(':push('(');
        break;
        case ')':cbraces(')');
        break;
        default:char_fun(c);
    }

}

while(top>=0){
    if(stack[top]!=')'){
        if(stack[top]!='('){
        output[j]=stack[top];
        j++;
        }
    }
    
    top--;
    
}

int r=0,s=4;
// printf("%d\n",q);
while(r<=s)
{
    int temp1;
    temp1=output[s];
    output[s]=output[r];
    output[r]=temp1;
    r++;
    s--;
    // printf("naman\n");
}


printf("Answer Is: %s\n",output);
}
//+,-,*,/ Functions
void plus(){
    int top1=top1;
    if(top==-1){
        push('+');
    }
    else if(stack[top]=='('){
        push('+');
    }
    else{
        for(int i=0;i<=3;i++){
            if(stack[top]==precedence[i].op){
                m=precedence[i].prec;
            }
        }
        if(m<1){
            push('+');
        }
        else if(m==1){
            char b=stack[top];
            output[j]=b;
            j++;
            stack[top]='+';
        }
        else{
            char b=stack[top];
            output[j]=b;
            j++;

            stack[top]='+';
        }
    }
}

void mul(){
    if(top==-1){
        push('*');
    }
    else if(stack[top]=='('){
        push('*');
    }
    else{
        for(int i=0;i<=3;i++){
            if(stack[top]==precedence[i].op){
                m=precedence[i].prec;
            }
        }
        if(m<2){
            push('*');
        }
        else if(m==2){
            char b=stack[top];
            output[j]=b;
            j++;
            stack[top]='*';

        }

    }
    

}

void division(){
    if(top==-1){
        push('/');
    }
    else if(stack[top]=='('){
        push('/');
    }
    else{
        for(int i=0;i<=3;i++){
            if(stack[top]==precedence[i].op){
                m=precedence[i].prec;
            }
        }
        if(m<2){
            push('/');
        }
        else if(m==2){
            char b=stack[top];
            output[j]=b;
            j++;
            stack[top]='/';

        }


    }
    

}

void minus(){
    int top1=top1;
    if(top==-1){
        push('-');
    }
    else if(stack[top]=='('){
        push('-');
    }
    else{
        for(int i=0;i<=3;i++){
            if(stack[top]==precedence[i].op){
                m=precedence[i].prec;
            }
        }
        if(m<1){
            push('-');
        }
        else if(m==1){
            char b=stack[top];
            output[j]=b;
            j++;

            stack[top]='-';
        }
        else{
            char b=stack[top];
            output[j]=b;
            j++;

            stack[top]='-';
        }
    }
}


void cbraces(){
    if(open_finder()){
        while(stack[top]!='('){
    output[j]=stack[top];
    top--;
    j++;}
    }
}

int open_finder(){
    int top1=top;
    char c;
    while(top1>=0){
        c=stack[top1];
        if(c='('){
            return 1;
        }else{
            return 0;
        }
        top1--;
    }
}
void char_fun(char c){
    output[j]=c;
    j++;
}
//Stack Functions
void push(char ele){
    
    if(isFull()){
        printf("Stack is overflowed\n");
    }
    else{
        top++;
        stack[top]=ele;
        
        
    }
}

int isFull(){
    if(top>9){
        return 1;
    }
    else{
        return 0;
    }
}

// int Length(){
//     int count=0;
//     for(int i=0;input[i]!='\0';i++){
//         count++;
//     }
//     return count;
// }

