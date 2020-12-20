#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.c"

void Traverse();
void threader();
void insert();
void insertion_traversal(struct node_thread*);
void ListAdder(struct node_thread*);
//Declaring node structure
struct node_thread
{
    struct node_thread *left;
    int data,isThread;
    struct node_thread *right;
};
struct node_thread* head=NULL,*temp;
int data=0;

void main(){
    int choice,control=1;
    while (control)
    {
        printf("Enter Your Choice: \n");
        printf("1.Inser Element\n");
        printf("2.Traverse\n");
        printf("3.Delete\n");
        printf("4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            threader();
            Traverse();
            
            break;
        // case 3:
        //     printf("Enter data: \n");
        //     scanf("%d", &delete_data);
        //     delete ();

        //     break;
        case 4:
            control=0;
            break;

        default:
            break;
        }
    }
}

void insert()
{
    temp = (struct node_thread *)malloc(sizeof(struct node_thread));
    printf("Enter Data: \n");
    scanf("%d", &data);
    temp->data = data;
    temp->isThread=0;
    temp->left = NULL;
    temp->right = NULL;
    if (head == NULL)
    {   root=NULL;
        head = temp;
        ListAdder(head);
    }
    else
    {   root=NULL;
        
        insertion_traversal(head);
        ListAdder(head);
    }
}

void insertion_traversal(struct node_thread *ptr)
{   printf("naman\n");
    if (data < ptr->data)
    {
        if (ptr->left != NULL)
        {
            insertion_traversal(ptr->left);
        }
    }
    if (ptr != NULL)
    {
        if (data > ptr->data)
        {
            if (ptr->right == NULL)
            {
                ptr->right = temp;
                
            }
        }
        else if (data < ptr->data)
        {
            if (ptr->left == NULL)
            {
                ptr->left = temp;
                
            }
        }
    }
    if (data > ptr->data)
    {
        if (ptr->right != NULL)
        {
            insertion_traversal(ptr->right);
        }
    }
    return;
}

void ListAdder(struct node_thread *ptr)
{  
    //  printf("i am here\n");
    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    if (ptr->left != NULL && ptr->isThread!=1)
    {   printf("specifically i am here %d\n",ptr->data);
        ListAdder(ptr->left);
    }
    if (ptr != NULL  && ptr->isThread!=1)
    {   printf("narendra\n");
        Append(ptr);
    }
    if (ptr->right != NULL  && ptr->isThread!=1 )
    {   printf("naman\n");
        ListAdder(ptr->right);
    
    }
    
    return;
}

void threader(){
    struct node* p,*q=root;
    p=root;
    while(p->link!=NULL){
        q=p->link;
        if(p->data->right==NULL && p->data->isThread!=1){
            if(q!=NULL){
            p->data->right=q->data;
            p->data->isThread=1;
            }
        }
        p=p->link;
    }
}


void Traverse(){
    struct node* p;
    p=root;
    if(p!=NULL){
        while(p->link!=NULL){
            printf("Your Element Is: %d\n\n",p->data->data);
            // printf("left side is:%d\n",p->data->left);
            // printf("right side is:%d\n",p->data->right);
            // printf("IsThreaded is:%d\n",p->data->isThread);
            p=p->link;
        }
        printf("Your Element Is: %d\n\n",p->data->data);
        // printf("left side is:%d\n",p->data->left);
        //     printf("right side is:%d\n",p->data->right);
        //     printf("IsThreaded is:%d\n",p->data->isThread);
    }
    else{
        printf("List is empty\n");
    }
}
