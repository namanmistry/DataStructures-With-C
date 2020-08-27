#include<stdio.h>
#include<stdlib.h>
void traverse();
void push();
int isEmpty();
int size,top=0,ele;
int *ptr;
int main(){
printf("Enter the size of the stack: ");
scanf("%d",&size);
ptr=(int*)calloc(size,sizeof(int));
int control=1,choice;
while(control){
  printf("Enter your choice:\n");
  printf("1.Push an element\n");
  printf("2.Pop an element\n");
  printf("3.To traverse\n");
  printf("4.Peek element\n");
  printf("5.Peep element\n");
  printf("6.Change\n");
  printf("7.Exit\n");

scanf("%d",&choice);
switch(choice){
    case 1:push();
    break;
    case 2:pop();
    break;
    case 3:traverse();
    break;
    case 4:peek();
    break;
    case 5:peep();
    break;
    case 6:change();
    break;
    case 7:control=0;
    break;
    default:printf("You entered invalid number!\n");
}
}

    
return 0;	
}

void push(){
    printf("Enter the element:\n");
    scanf("%d",&ele);
    if(isFull()){
        printf("Stack is overflowed\n");
    }
    else{
        top++;
        ptr[top]=ele;
        printf("Element pushed successfully");
        printf("noe top value is: %d",top);
        
    }
}


void pop(){
    int temp;
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else{
        temp=*(ptr+top);
        --top;
        printf("Element popped successfully\n");
    }

}
int isEmpty(){
    if(top<=0){
        printf("Stack is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top>=size){
        return 1;
    }
    else{
        return 0;
    }
}

void traverse(){
    int i=1;
    int top1=top;
    printf("Elements:\n");
    while(top1>=i){
        printf("Element %d is: %d\n",top,*(ptr+top1));
        top1--;
    }
}

void peek(){
    printf("peek element is: %d\n",*(ptr+top));
}

void peep(){
    int index,temp;
    
    printf("Enter The Index Number: \n");
    scanf("%d",&index);
    temp=top-index+1;
    if(temp>0){
    printf("YOur Element Is: %d\n",*(ptr+(top-index+1)));
    }
    else{
        printf("The Element You Want To Get Doesn't Exist\n");
    }

}

void change(){
    int index,ele;
    printf("Enter The Index That You Want To Change: \n");
    scanf("%d",&index);
    printf("Enter The New Element: \n");
    scanf("%d",&ele);
    *(ptr+(top-index+1))=ele;

}