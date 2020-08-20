#include<stdio.h>
#include<stdlib.h>

//Global Variables
int front=0,rear=0,ch,size;
int *p;

//Prototypes Of Functions
void Insertion();
void Traverse();
void Deletion();
//Starting Of Declarations Of Functions
void main(){
printf("Enter The Size Of The Queue\n");
scanf("%d",&size);
p=(int*)calloc(size,sizeof(int));
int control=1;
while(control){
printf("Enter Your Choice:\n");
printf("1.Insertion\n");
printf("2.Deletion\n");
printf("3.Traverse\n");
printf("4.Exit\n");
scanf("%d",&ch);

switch(ch){
    case 1:Insertion();
    break;
    case 2:Deletion();
    break;
    case 3:Traverse();
    break;
    case 4:control=0;
    break;
    default:printf("You Entered Wrong Choice\n");
}
}
}

void Insertion(){
    int data;
    printf("Enter the data you want ot enter: \n");
    scanf("%d",&data);
    if(rear==size){
        printf("naman\n");
        rear=0;
        if(p[rear]==0){
            p[rear]=data;
            rear++;
        }
        else{
            printf("Queue is full\n");
        }
        
    }
    else if(p[rear]==0){
    p[rear]=data;
    rear++;
    }
    else{
        printf("Queue is full\n");
    }
}

void Deletion(){
    if(p[front]!=0){
        p[front]=0;
        front++;
    }
    else{
        printf("Queue is empty\n");
    }
}

void Traverse(){
    int temp=front;
    int times=0;
    while(times<5){
        if(temp==size){
            temp=0;
        }
        if(p[temp]!=0){
        printf("Your element is:%d\n",p[temp]);
        }
        times++;
        temp++;
    }
}

//Ending Of the Declarations Of Functions