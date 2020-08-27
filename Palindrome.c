#include<stdio.h>
#include<stdlib.h>
void traverse();
void push();
int isEmpty();
int size,top=-1,ele,number,d1,d2;
int *ptr,*p;
void main(){
printf("Enter the size of the Number: \n");
scanf("%d",&size);
ptr=(int*)calloc(size,sizeof(int));
p=(int*)calloc(size,sizeof(int));
printf("Enter The Number: \n");
scanf("%d",&number);
d2=number;
for(int i=0;i<size;i++){
d1=number%10;
p[i]=d1;
number=number/10;
// printf("%d %d\n",d1,i);
}

for(int j=size-1;j>=0;j--){

    push(p[j]);
}


Palindrome();
}


void Palindrome(){
    int n=1,m=1,temp,sum=0,top1=top;

while(n<=size){
    temp=ptr[top1];
    printf("%d\n",temp);
    m=1;
  while(m<=size-n){
      
      temp=temp*10;
      m++;
      printf("%d",temp);
  }
  sum=sum+temp;
    n++;
    top1--;
}

if(sum==d2){
    printf("Number Is Palindrome\n");
}
else{
    printf("Number Is Not Palindrome\n");
}

}
    


void push(int d1){
    
    if(isFull()){
        printf("Stack is overflowed\n");
    }
    else{
        top++;
        ptr[top]=d1;
        
        
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
    int i=0,top1=top;
    
    printf("Elements:\n");
    while(top1>=i){
        printf("Element %d is: %d\n",top1,*(ptr+top1));
        top1--;
    }
}

void peek(){
    printf("peek element is: %d\n",*(ptr+top));
}

void peep(){
    int index;
    printf("Enter The Index Number: \n");
    scanf("%d",&index);
    printf("YOur Element Is: %d\n",*(ptr+(top-index+1)));

}

void change(){
    int index,ele;
    printf("Enter The Index That You Want To Change: \n");
    scanf("%d",&index);
    printf("Enter The New Element: \n");
    scanf("%d",&ele);
    *(ptr+(top-index+1))=ele;

}