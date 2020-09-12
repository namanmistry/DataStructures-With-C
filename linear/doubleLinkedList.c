#include<stdio.h>
#include<stdlib.h>

void Append();
void AddAtBegin();
void AddNodeAfter();
void Delete();
void Swap(int,int);
void Sort();
void Ascending();
void Descending();
void Reverse();
int Length();
int Value(int);
void Traverse();

struct node{
    struct node*prev;
    int data;
    struct node *next;
};

struct node* root=NULL;
void main(){
    int ch1,ch2;
    int control=1,choice;
     while (control)
    {
        printf("Enter Your Choice\n");
        printf("1.Append Node\n");
        printf("2.Add Node At Begin\n");
        printf("3.Add Node After\n");
        printf("4.Display All Nodes\n");
        printf("5.Delete Node\n");
        printf("6.Swap Node\n");
        printf("7.Sort\n");
        printf("8.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Append();
            break;
        case 2:
            AddAtBegin();
            break;
        case 3:
            AddNodeAfter();
            break;
        case 4:
            Traverse();
            break;
        case 5:
            Delete();
            break;
        case 6:
            printf("Enter number of first element: \n");
            scanf("%d",&ch1);
            printf("Enter number of second element: \n");
            scanf("%d",&ch2);
            Swap(ch1,ch2);
            break;
        case 7:
            Sort();
            break;
        case 8:
            control=0;
            break;
    }
    }
}

void Append(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(root==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        printf("Enter Node Data: \n");
        scanf("%d",&temp->data);
        root=temp;
        temp=NULL;
    }
    else{
        int data;
        printf("hello");
        struct node *p;
        p=root;
        while(p->next!=NULL)p=p->next;
        printf("Enter Node Data: \n");
        scanf("%d",&data);
        printf("%d",data);
        temp->data=data;
        p->next=temp;
        temp->prev=p;
        temp->next=NULL;
    }
}

void AddAtBegin(){
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data: \n");
    scanf("%d",&temp->data);
    p=root;
    root=temp;
    temp->prev=NULL;
    temp->next=p;
}

void AddNodeAfter(){
    int nodeNumber,count=1;
    printf("Enter after which node you want to enter: \n");
    scanf("%d",&nodeNumber);
    printf("Length is: %d\n",Length());
    struct node *temp,*p;
    p=root;
    temp=(struct node*)malloc(sizeof(struct node));
    while(count<nodeNumber){
        p=p->next;
        count++;
    }
    if(nodeNumber==Length()){
        printf("Enter the node data: \n");
        scanf("%d",&temp->data);
        p->next=temp;
        temp->prev=p;
        temp->next=NULL;
    }
    else if(nodeNumber==0)AddAtBegin();
    else{
        printf("Enter the node data1: \n");
        scanf("%d",&temp->data);
        temp->next=p->next;
        temp->prev=p;
        p->next=temp;
        p=p->next;
        p=p->next;
        p->prev=temp;
    }
}

void Delete(){
    int control=1;
    while(control){
    printf("1.Delete First Node\n");
    printf("2.Delete Last Node\n");
    printf("3.Delete After Some Node\n");
    printf("4.Exit\n");
    int choice;
    printf("   Enter your choice: \n");
    scanf("%d",&choice);
    struct node *p;
    p=root;
    if(choice==1){
        root=p->next;
        p->prev=NULL;
        p->next=NULL;
        free(p);
    }
    else if(choice==2){
        int count=1;
        struct node *p;
        p=root;
        while(count<Length()-1){
        p=p->next;
        count++;
        }
        p->next=NULL;
    }
    else if(choice==3){
        printf("   Enter the number of the node that you want to delete: \n");
        int nodeNumber;
        scanf("%d",&nodeNumber);
        if(nodeNumber==1){
            root=p->next;
            p->prev=NULL;
            p->next=NULL;
            free(p);
        }
        else if(p->next==NULL){
            root==NULL;
        }
        else if(nodeNumber==Length()){
            int count=1;
            struct node *p;
            p=root;
            while(count<Length()-1){
            p=p->next;
            count++;
        }
        p->next=NULL;

        }
        else{
            int count=1;
            p=root;
            while (count<nodeNumber){
            p=p->next;
            count++;
            }
        struct node *temp;
        struct node *temp1;
        temp=p->next;
        temp1=p->prev;
        p->next=NULL;
        p->prev=NULL;
        temp1->next=temp;
        temp->prev=temp1;
        
        }
    }
    else if(choice==4){
        control=0;
    }
    }
}

void Swap(int ch1,int ch2){
    if(ch1>ch2){
        int temp;
        temp=ch1;
        ch1=ch2;
        ch2=temp;
    }
    struct node* p,*q;
    p=root;
    q=root;
    int countp=1,countq=1;
    while(countp<ch1){
        p=p->next;
        countp++;
    }
    while(countq<ch2){
        q=q->next;
        countq++;
    }
    struct node *temp1;
    struct node *temp2;
    struct node *temp3;
    struct node *temp4;
    struct node *temp5;
    struct node *temp6;
    if(ch1-ch2==1||ch1-ch2==-1 && ch1!=1 && ch2!=1 && ch1!=Length() && ch2!=Length()){
        if(ch1!=1||ch2!=1){
        temp1=p;
        temp3=p;
        temp2=q->next;
        p=p->prev;
        p->next=q;
        q->next=temp1;
        temp1->next=temp2;
        q->prev=p;
        temp1->prev=q;
        temp1=temp1->next;
        temp1->prev=temp3;
        
        }
    }
    else if(ch1==1||ch2==1){
        if(ch1==Length()||ch2==Length()){
            temp1=p;
            temp2=q;
            root=q;
            q=q->prev;
            temp2->next=temp1->next;
            q->next=temp1;
            temp1->next=NULL;
            temp1->prev=q;
            temp2->prev=NULL;
            temp3=temp2;
            temp2=temp2->next;
            temp2->prev=temp3;

        }
        else if(ch1==2||ch2==2){
            temp1=root;
            temp2=q->next;
            root=temp1->next;
            q->prev=NULL;
            q->next=temp1;
            temp1->next=temp2;
            temp1->prev=root;
            p=p->next;
            p->prev=temp1;

        }
        else{
        temp2=q->prev;
        temp3=q->next;
        temp1=root;
        root=q;
        q->prev=NULL;
        q->next=temp1->next;
        temp2->next=temp1;
        temp1->next=temp3;
        temp1->prev=temp2;
        temp3->prev=temp1;
        }
    }
    else{
        if(ch1==Length()||ch2==Length()){
           temp1=p;
           temp2=q;
           p=p->prev;
           q=q->prev;
           p->next=temp2;
           q->next=temp1;
           temp2->next=temp1->next;
           temp1->next=NULL;
           temp1->prev=q;
           temp2->prev=p;
           temp3=temp2;
           temp2=temp2->next;
           temp2->prev=temp3;
        }
    else{
        temp1=p;
        temp2=q;
        p=p->prev;
        q=q->prev;
        p->next=temp2;
        q->next=temp1;
        temp3=temp2->next;
        temp2->next=temp1->next;
        temp1->next=temp3;
        temp2->prev=p;
        temp1->prev=q;
        temp4=temp2;
        temp2=temp2->next;
        temp2->prev=temp4;
        temp5=temp1;
        temp1=temp1->next;
        temp1->prev=temp5;
    }
    }
}

void Sort()
{
    int control = 1, ch;
    while (control)
    {
        printf("What Operation Do You Want TO Perform?\n");
        printf("1.Ascending\n");
        printf("2.Descending\n");
        printf("3.Reverse\n");
        printf("4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Ascending();
            break;
        case 2:
            Descending();
            break;
        case 3:
            Reverse();
            break;
        case 4:
            control = 0;
            break;
        default:
            printf("You Entered Wrong Choice\n");
        }
    }
}

void Descending()
{
    for (int i = 1; i <= Length() - 1; i++)
    {
        for (int j = i + 1; j <= Length(); j++)
        {
            if (Value(i) < Value(j))
            {
                Swap(i, j);
            }
        }
    }
}

void Ascending()
{
    for (int i = 1; i <= Length()-1; i++)
    {
        for (int j = i + 1; j <= Length(); j++)
        {
            if (Value(i) > Value(j))
            {
                Swap(i, j);
            }
        }
    }
}
void Reverse()
{
    int count1 = 1, count2 = Length();
    if (root != NULL)
    {
        while (count1 <= count2)
        {
            Swap(count1, count2);
            count1++;
            count2--;
        }
    }
    else
    {
        printf("List Is Empty\n");
    }
}

int Value(int i)
{
    struct node *temp;
    temp = root;
    int count = 1;
    while (count < i)
    {
        temp = temp->next;
        count++;
    }
    return temp->data;
}

int Length(){
    struct node *p;
    p=root;
    int count=1;
    while(p->next!=NULL){
        p=p->next;
        count++;
    }
    return count;
}

void Traverse(){
    struct node *p;
    p=root;
    while(p->next!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}