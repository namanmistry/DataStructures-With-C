#include<stdio.h>
#include<stdlib.h>

//Global Variables
int front=0,rear=0,ch,size;
int *p;
int leftRear=0,rightRear;

//Prototypes Of Functions
void Insertion();
void Traverse();
void Deletion();
//Starting Of Declarations Of Functions
void main(){
printf("Enter The Size Of The Queue\n");
scanf("%d",&size);
rear=size;
rightRear=size-1;
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




void Traverse(){
    if(front==rear){
        printf("Queue Is Empty\n");
    }
    else{
        for(int i=0;i<size;i++){
            
            printf("Element is:%d\n",p[i]);
            
        }
    }

    }




void Insertion(){
int ch,data;
printf("Enter at which side you want to enter: \n");
printf("1.Front\n");
printf("2.Rear\n");
scanf("%d",&ch);
printf("Enter the data\n");
scanf("%d",&data);
if(ch==1){
    if(leftRear<=rightRear && p[rightRear]==0){
    if(leftRear==0){
    p[0]=data;
    leftRear++;
    }
    else{
        printf("leftear is:%d\n",leftRear);
        if(leftRear!=size){
        for(int i=leftRear-1;i>=0;i--){
            p[i+1]=p[i];
        }
        p[0]=data;
        leftRear++;
        }
        else{
            printf("Queue is full1\n");
        }
    }
    }
    else{
        printf("Queue is already full\n");
    }
}
else if(ch==2){
    if(rightRear>=leftRear && p[leftRear]==0){
    if(rightRear==size-1){
        p[size-1]=data;
        rightRear--;
    }
    else{
        printf("rightRear is:%d\n",rightRear);
        if(rightRear<0){
            printf("Queue is full\n");
        }
        else{
            
            for(int j=rightRear+1;j<=size-1;j++){
                p[j-1]=p[j];
            }
            
            p[size-1]=data;
            rightRear--;
        }
    }
    }
    else{
        printf("Queue is already full2\n");
    }

}

}


void Deletion(){
    if(front==rear){
        printf("Queue Is Empty\n");
    }
    else{
        for(int i=0;i<rear;i++){
            p[i]=*(p+i+1);
            
        }
        rear--;
    }
}
//Ending Of the Declarations Of Functions