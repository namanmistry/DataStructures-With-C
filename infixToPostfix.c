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

int m,n,o;

void main(){
//Scanning The expression
printf("Enter The Expression: \n");
scanf("%s",&input);

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
            printf("namanbhia\n");
            char b=stack[top];
            output[j]=b;
            j++;
        //     for(int i=0;i<=3;i++){
        //     if(stack[top]==precedence[i].op){
        //         o=precedence[i].prec;
        //     }
        // }
            if(m>1){
                char d=stack[top-1];
                output[j]=d;
                j++;
                top--;
                
            }
            else{
                // top++;
                plus();
            }
            
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
