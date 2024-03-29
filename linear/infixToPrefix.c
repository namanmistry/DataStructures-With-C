#include<stdio.h>
#include<string.h>
int stackPrecedence();
int nextCharPrecedence(char);
void push(char);
char pop();
void reverse();
//Declarations of global variables
struct prec{
    char sym;
    int prec;
};
struct prec inputPrec[]={{'+',1},{'-',1},{'*',3},{'/',3},{'^',6},{'(',9},{')',0}};
struct prec stackPrec[]={{'+',2},{'-',2},{'*',4},{'/',4},{'^',5},{'(',0}};
int top=-1;
char stack[50];
char input[50];
char output[50];

void main(){
    int i=0,j=0,k=0;
    printf("Enter the expression: \n");
    scanf("%s",input);
    if(rank()==1){
    strrev(input);
    while(input[k]!='\0'){
        if(input[k]==')'){
            input[k]='(';
        }
        else if(input[k]=='('){
            input[k]=')';
        }
        k++;
    }
    push('(');
    // printf("input is:%s\n",input);
    while(input[i]!='\0'){
        if(nextCharPrecedence(input[i])>stackPrecedence()){
            if(nextCharPrecedence(input[i])!=0){
            push(input[i]);
            }
        }
        else if(nextCharPrecedence(input[i])<stackPrecedence() && nextCharPrecedence(input[i])!=0){
            while(nextCharPrecedence(input[i])<stackPrecedence()){
                char temp=pop();
                if(temp!='(' && temp!=')'){
                    output[j]=temp;
                    j++;
                }
            }
            if(input[i]!=')'){
    
            push(input[i]);
            }
        }
        else if(nextCharPrecedence(input[i])==0){
            while(stack[top]!='('){
                char temp=pop();
                if(temp!='(' && temp!=')'){
                output[j]=temp;
                j++;
                }
            }
            char temp1=pop();
           
        }
        i++;
    }

    while(top!=-1){
       
        char temp=pop();
        if(temp!='(' && temp!=')'){
        output[j]=temp;
        j++;
    }
        }
    strrev(output);
    printf("Ans is:%s",output);
    }
    else{
        printf("Please enter valid expression\n");
    }
}

int stackPrecedence(){
    for(int i=0;i<6;i++){
        if(stack[top]==stackPrec[i].sym){
            return stackPrec[i].prec;
        }
    }
    return 8;
}

int nextCharPrecedence(char ch){
    for(int i=0;i<7;i++){
        if(ch==inputPrec[i].sym){
            return inputPrec[i].prec;
        }
    }
    return 7;
}

void push(char ch){
    top++;
    stack[top]=ch;
}

char pop(){
    char temp=stack[top];
    --top;
    return temp;
}

int rank(){
    int x=0;
    int rank=0;
    while(input[x]!='\0'){
        if(input[x]=='+'|| input[x]=='-'||input[x]=='*'||input[x]=='/'||input[x]=='^'){
            rank--;
        }
        else{
            rank++;
        }
        x++;
    }
    return rank;
}
    
