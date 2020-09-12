#include<stdio.h>
void push(int);
int pop();
int performOperation(char,int,int);

int  stack[20];
char input[50];
int output,top=-1,i=0,j=0;

void main(){
    printf("Enter the expression: \n");
    scanf("%s",input);
    while(input[i]!='\0'){
        if(isdigit(input[i])){
            push(input[i]-'0');
        }
        else{
            int operand_1=pop();
            int operand_2=pop();
            int result =performOperation(input[i],operand_1,operand_2);
            push(result);
        }
        i++;
    }
    output=pop();
    printf("Ans is:%d\n",output);

}

void push(int value){
    top++;
    stack[top]=value;
}

int pop(){
    int temp=stack[top];
    top--;
    return temp;
}

int performOperation(char operator,int operand_1,int operand_2){
    int result;
    switch(operator){
        case '+':result=operand_1+operand_2;
        break;
        case '-':result=operand_2-operand_1;
        break;
        case '*': result=operand_1*operand_2;
        break;
        case '/':result=operand_2/operand_1;
        break;
    }
    return result;
}