#include<stdio.h>
#include<stdlib.h>

//Start Of Declaration Of Global Variables
struct node{
    int data;
    struct node* link;
};
struct node *root,*local=NULL;
//End Of Declaration Of Global Variables



//Start Of Functions
void main(){
    int ch,control=1,l;
    while(control){
    printf("\033[1;34mEnter YOur Choice: \033[0m\n");
    printf("\033[1;33m1.Push An Element\n");
    printf("2.Traverse The Stack\n");
    printf("3.End The Program\n");
    printf("4.Pop The Element\n");
    printf("5.Peek Element\n");
    printf("6.Peep An Element\n");
    printf("7.Length Of Stack\033[0m\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:Push();
        break;
        case 2:Traverse();
        break;
        case 3:control=0;
        break;
        case 4:Pop();
        break;
        case 5:Peek();
        break;
        case 6:Peep();
        break;
        case 7:l=Length();
        printf("\033[1;35mLength Of The Stack Is:%d\033[0m\n",l);
        break;
        default:printf("You Entered Wrong Number!\n");
    }
    	
    }
}

void Push(){

    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    // root=temp;
    
    printf("Enter The Node Data: ");
    scanf("%d",&temp->data);
    
    temp->link=local;
    local=temp;
    
}

void Traverse(){
    struct node *p;
    p=local;
    
    if(local!=NULL){
    printf("\033[1;31mElements are: \033[0m\n");
    while(p->link!=NULL){
        printf("\033[1;33m|%d|\n",p->data);
        
        
        p=p->link;
    }
    printf("\033[1;33m|%d|\033[0m\n",p->data);
    printf("\033[1;33m -\033[0m\n");
    
    }
    else{
        printf("Stack Is Empty\n");
    }
}

void Pop(){
    if(isEmpty()){
    printf("Stack Is Already Empty\n");
    }
    else{
        if(local->link!=NULL){
            local=local->link;}
        else{
            local=NULL;
}
    
    }
}

int isEmpty(){
    if(local==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


void Peek(){
    if(isEmpty()){
        printf("\033[1;31mStack IS Empty\033[0m\n");
    }
    else{
    printf("\033[1;32mYour Element Is: %d\033[0m\n",local->data);
    }
}

void Peep(){
    int index,count=1;
    struct node* temp;
    temp=local;
    printf("Enter The Index Number: \n");
    scanf("%d",&index);
    
    if(index<=Length()){
    while(count<index){
     temp=temp->link;
     count++;
    }
    printf("\033[1;35mYour Element is: %d\033[0m\n",temp->data);
    }
    else{
        printf("The Element That You Want To Show Doesn't Exist\n");
    }
}

int Length(){
    int count=1;
    struct node *temp;
    temp=local;
    while(temp->link!=NULL){
        temp=temp->link;
        count++;
    }
    return count;
    

}
//End Of Functions