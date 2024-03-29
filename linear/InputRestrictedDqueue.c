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
    if(rear==size){
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
        for(int i=0;i<rear;i++){
            printf("%d\n",*(p+i));
    }

    }
}

void Deletion(){
    if(front==rear){
        printf("Queue is empty\n");
    }
    else{
    int ch;
    printf("From which end you want to delete\n");
    printf("1.Front\n");
    printf("2.Rear\n");
    scanf("%d",&ch);
    if(ch==1){
        for(int i=0;i<rear;i++){
            p[i]=p[i+1];
        }
        rear--;
        
    }
    else if(ch==2){
        rear--;
    }
    else{
        printf("Operation Invalid\n");
    }
    }
}
//Ending Of the Declarations Of Functions