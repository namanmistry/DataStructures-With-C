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
    printf("Enter The Element You Want To Enter: \n");
    scanf("%d",&data);
    if(rear>=size){
        printf("Queue Is Full\n");
    }
    else{
        
        p[rear]=data;
        rear++;
    }
    printf("%d\n",rear);
}


void Traverse(){
    if(front==rear){
        printf("Queue Is Empty\n");
    }
    else{
        printf("Elements Are: \n");
        for(int i=front;i<rear;i++){
            printf("%d\n",p[i]);
    }

    }
}

void Deletion(){
    if(front==rear){
        printf("Queue Is Empty\n");
    }
    else{
        printf("front id:%d\n",front);
        front++;
    }
}
//Ending Of the Declarations Of Functions