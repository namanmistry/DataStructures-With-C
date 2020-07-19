#include<stdio.h>
#include<stdlib.h>

//Declaring Prototypes
void Append();
void AddAtBegin();
void Display();
void AddAfter();
void Delete1();
int Length();
void Swap();
void Sort();
void Ascending();
void Descending();
void Reverse();
//Global Variables
struct node{
    int data;
    struct node*  link;
};
struct node* root=NULL;


//Start Of Definations Of Functions
void main(){

int control=1,choice;

while(control){
    printf("Enter Your Choice\n");
    printf("1.Append Node\n");
    printf("2.Add Node At Begin\n");
    printf("3.Add Node After\n");
    printf("4.Display All Nodes\n");
    printf("5.Delete Node\n");
    printf("6.Swap Node\n");
    printf("7.Sort\n");
    printf("8.Exit\n");

    scanf("%d",&choice);

    switch(choice){
        case 1:Append();
        break;
        case 2:AddAtBegin();
        break;
        case 3:AddAfter();
        break;
        case 4:Display();
        break;
        case 5:Delete1();
        break;
        case 6:Swap();
        break;
        case 7:Sort();
        break;
        case 8:control=0;
        break;
        default:printf("You Entered Wrong Choice\n");
    }

}
}

void Append(){

    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    
    if(root==NULL){
        printf("Enter The Node Data: ");
        scanf("%d",&temp->data);
        temp->link=NULL;
        root=temp;
    }
    else{
        
        struct node* p;
        p=root;
        
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
        printf("Enter The Node Data: ");
        scanf("%d",&temp->data);
        temp->link=NULL;
    }
}

void Display(){
    if(root!=NULL){
    struct node* temp;
    
    temp=root;
    
        while(temp->link!=NULL){
            
            printf("Your Element is: %d\n",temp->data);
            temp=temp->link;
        }

    printf("Your Element is: %d\n",temp->data);
    
    }
    else{
        printf("Linked List Is Already Empty\n");

    }
    
    
    
}

void AddAtBegin(){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(root==NULL){
        printf("ENter Node Data: \n");
        scanf("%d",&temp->data);
        root=temp;
    }
    else{
        printf("ENter Node Data: \n");
        scanf("%d",&temp->data);
        temp->link=root;
        root=temp;
    }

}

void AddAfter(){
    int ch,count1=1,count2=1;
    struct node *temp,*p,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data: \n");
    scanf("%d",&temp->data);
    p=root;
    q=root;
    printf("After Which Node You Want To Insert New Node: \n");
    scanf("%d",&ch);
    while(count1<=ch){
        if(q!=NULL){
        q=q->link;
        }
        else{
        q->link=temp;
        temp->link=NULL;
        }
        count1++;
    }
    temp->link=q;
    while(count2<ch){
        p=p->link;
        
        count2++;
    }
    p->link=temp;
}


int Length(){
    struct node* temp;
    temp=root;
    int count=1;
    while(temp!=NULL){
        temp=temp->link;
        count++;
    }
    return count-1;
}

void Delete1(){
    int selection,count1=1,count2=1,count3=1;
    struct node *p,*q;
    
    p=root;
    q=root;
    printf("Enter The Node That You Want To Delete: \n");
    scanf("%d",&selection);

    if(selection==1){
        if(root->link!=NULL){
        struct node* temp;
        temp=root;
        temp=temp->link;
        root->link=NULL;
        root=temp;
        }
        else{
            root=NULL;
        }

    }
    else if(selection==Length()){
        struct node* temp;
        temp=root;
        int count=1;
        while(count<Length()-1){
            temp=temp->link;
            count++;
        }
        temp->link=NULL;
    }
    
    else if(1<selection<Length()){
        struct node* temp;
        temp=root;
    //     while(count3<selection){
    //     q=q->link;
    //     count3++;
    // }
    // q->link=NULL;
    // free(q);

    while(count1<selection-1){
        
        temp=temp->link;
        count1++;
    }
    while(count2<=selection){
        p=p->link;
        
        count2++;
    }
    temp->link=p;
    
    printf("hello this is naman mistry");
    Display();
    printf("%x",temp->link);
    }

    else{
        printf("The Node You Want To Delete Does Not Exists\n");
    }
}

void Swap(){
    int count1=1,ch1,ch2,count2=1,temp;
    struct node* p1,*p2;
    p1=root;
    p2=root;

    printf("Enter The First Element:  \n");
    scanf("%d",&ch1);
    printf("Enter The Second Element: \n");
    scanf("%d",&ch2);
    if(1<=ch1<=Length()&&1<=ch2<=Length()){
    while(count1<ch1){
        p1=p1->link;
        count1++;
    }
    while(count2<ch2){
        p2=p2->link;

        count2++;
    }
    temp=p1->data;
    p1->data=p2->data;
    p2->data=temp;
    }
    else{
        printf("The Element You Want To Swap Doesn't Exit\n");
    }
    
}

void Sort(){
    int control=1,ch;

    while(control){
    printf("What Operation Do You Want TO Perform?\n");
    printf("1.Ascending\n");
    printf("2.Descending\n");
    printf("3.Reverse\n");
    printf("4.Exit\n");
    scanf("%d",&ch);
    
    switch(ch){
        case 1:Ascending();
        break;
        case 2:Descending();
        break;
        case 3:Reverse();
        break;
        case 4:control=0;
        break;
        
        default:printf("You Entered Wrong Choice\n");
    }
    
    
    }
}

void Ascending(){
    if(root!=NULL){
    struct node *temp,*p;
    int d1,d2;
    temp=root;
    
    
    while(temp->link!=NULL){
        
        p=temp;
        

        while(p->link!=NULL){
            
            if(temp->data>p->data){
                int i;
                i=p->data;
                p->data=temp->data;
                temp->data=i;
                
            }
            else{
                p=p->link;
                
            }
            
        }
        if(temp->data>p->data){
                int i;
                i=p->data;
                p->data=temp->data;
                temp->data=i;
                
            }

        temp=temp->link;
        
        
    }
    }
    else{
        printf("List Is Empty\n");
    }
    
    
}


void Descending(){
    if(root!=NULL){
    struct node *temp,*p;
    int d1,d2;
    temp=root;
    
    
    while(temp->link!=NULL){
        
        p=temp;


        while(p->link!=NULL){
            
            if(temp->data<p->data){
                int i;
                i=p->data;
                p->data=temp->data;
                temp->data=i;
                
            }
            else{
                p=p->link;
                
            }
            
        }
        if(temp->data<p->data){
                int i;
                i=p->data;
                p->data=temp->data;
                temp->data=i;
                
            }

        temp=temp->link;
        
        
    }
    }
    else{
        printf("List IS Empty\n");
    }
    
    
}

void Reverse(){
    if(root!=NULL){
    struct node *p,*q;
    int length=Length(),temp,count,count1=1;
    p=root;
    
    while(count1<count){
        
        q=root;
        count=1;
        while(count<length){
            
            q=q->link;
            
            count++;
            
        }
        
        temp=q->data;
        q->data=p->data;
        p->data=temp;
    
        length--;
        p=p->link;
        count1++;
    }
    }
    else{
        printf("List Is Empty\n");
    }
    
}
//End OF Declaration OF Functions