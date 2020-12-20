#include<stdio.h>
#include<stdlib.h>

struct node* insert_position_finder(int,struct node*);
struct node* node_finder(int,struct node*,struct node**);
struct node* least_node_from_subtree(struct node*);
struct node* last_node_finder();
struct node{
 int data;
 struct node* left;
 struct node* right;
 int threaded;
};
struct node* root=NULL;
struct node** left_add;
int length=0;
void main(){
    int control=1;
    int ch,l;
    while (control){
    printf("Enter Your Choice: \n");
    printf("1.insert\n");
    printf("2.traverse\n");
    printf("3.length\n");
    printf("4.threading\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        create();
        break;
    case 2:
        inorder(root);
        break;
    case 3:
        printf("Length is: %d\n",length);
        break;
    // case 4:
    // inorder_successor();
    // break;
    default:
        break;
    }
    }
}

void create(){
    struct node* p;
    p=(struct node*)calloc(1,sizeof(struct node));
    printf("Enter the data: \n");
    scanf("%d",&p->data);
    p->left=NULL;
    p->right=NULL;
    p->threaded=0;
    if (root==NULL){
        root=p;
        length++;
    }
    else{

        struct node* ptr;
        ptr=insert_position_finder(p->data,root);
        if (p->data<ptr->data){
            ptr->left=p;
            length++;
        }
        else if (p->data>ptr->data){
            ptr->right=p;
            length++;
        }
        threading(root);
    }
}

struct node* insert_position_finder(int data,struct node* p){
    
    if (data<p->data){
        if (p->left==NULL){
            return p;
        }
        else{
            insert_position_finder(data,p->left);
        }
    }
    else if (data>p->data){
        if (p->right==NULL){
            return p;
        }
        else{
            
            insert_position_finder(data,p->right);
            
        }
    }
}

void inorder(struct node* p){
    if(p==NULL){
        printf("Tree is Empty\n");
    }
    if (p->left!=NULL){
        inorder(p->left);
    }
    if (p!=NULL){
        printf("Element is: %d\n",p->data);
        printf("is thread: %d\n",p->threaded);
        printf("right: %d\n",p->right);
    }
    if (p->right!=NULL){
        if (p->threaded==0){
        inorder(p->right);
        }
    }
    return;
}

void inorder_successor(int data){
    //Here there are two cases
    struct node* temp;
    struct node* last_left_turn=NULL;
    struct node* last_node=last_node_finder();
    temp=node_finder(data,root,&last_left_turn);
    if(data!=last_node->data){
    if (temp->right!=NULL){
        struct node* successor=least_node_from_subtree(temp->right);
        temp->right=successor;
        temp->threaded=1;
    }
    else{
        temp->right=last_left_turn;
        temp->threaded=1;
    }
    }
}

struct node* least_node_from_subtree(struct node* p){
    
    while(p->left!=NULL){
        p=p->left;
    }
    return p;
}

struct node* node_finder(int data,struct node* p,struct node** last_left){
    
    while(p->data!=data){
        if(data<p->data){
            *(last_left)=p;
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    return p;
}

struct node* last_node_finder(){
    struct node* p=root;
    while(p->right!=NULL){
        p=p->right;
    }
    return p;
}

void threading(struct node* p){
    if(p==NULL){
        printf("Tree is Empty\n");
    }
    if (p->left!=NULL){
        threading(p->left);
    }
    if (p->right==NULL && p->threaded==0){
        inorder_successor(p->data);
    }
    if (p->right!=NULL){
        if (p->threaded==0){
        threading(p->right);
        }
    }
    return;
}