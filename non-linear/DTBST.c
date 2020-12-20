#include<stdio.h>
#include<stdlib.h>

struct node* insert_position_finder(int,struct node*);
struct node* first_node_finder(struct node*);
struct node* node_finder(int,struct node*,struct node**);
struct node* maximum_node_from_subtree(struct node*);
struct node* least_node_from_subtree(struct node*);
struct node* last_node_finder();

void inorder_predecessor();

struct node{
    int data,lthreaded,rthreaded;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;
int length=0,data;

void main(){
    int control=1,ch;
    while (control)
    {
        printf("Enter Your Choice: \n");
        printf("1.insert\n");
        printf("2.traverse\n");
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
        printf("Enter the data: \n");
        scanf("%d",&data);
            inorder_predecessor(data);
            break;
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
    p->lthreaded=0;
    p->rthreaded=0;
    if(root==NULL){
        root=p;
        length++;
    }
    else{
        struct node* ptr;
        ptr=insert_position_finder(p->data,root);
        printf("ptr to data is: %d\n",ptr->data);
        if (p->data<ptr->data){
            if(ptr->lthreaded==1){
                ptr->lthreaded=0;
            }
            ptr->left=p;
            length++;
        }
        else if (p->data>ptr->data){
            printf("namanam\n");
            if(ptr->rthreaded==1){
                ptr->rthreaded=0;
            }
            ptr->right=p;
            length++;
        }
        lthreading(root);
        rthreading(root);
    }
}

struct node* insert_position_finder(int data,struct node* p){
    
    if (data<p->data){
        if (p->left==NULL || p->lthreaded==1){
            return p;
        }
        else{
            if(p->lthreaded==0){

            insert_position_finder(data,p->left);
            }
        }
    }
    else if (data>p->data){
        if (p->right==NULL || p->rthreaded==1){
            return p;
        }
        else{
            if(p->rthreaded==0){

            insert_position_finder(data,p->right);
            }
            
        }
    }
}

void inorder(struct node* p){
    if(p==NULL){
        printf("Tree is Empty\n");
    }
    if (p->left!=NULL){
        if (p->lthreaded==0){
        inorder(p->left);
        }
    }
    if (p!=NULL){
        printf("Element is: %d\n",p->data);
        printf("is lthread: %d\n",p->lthreaded);
        printf("is rthread: %d\n",p->rthreaded);
        printf("right: %d\n",p->left);
    }
    if (p->right!=NULL){
        if (p->rthreaded==0){
        inorder(p->right);
        }
    }
    return;
}


void inorder_predecessor(int data){

    struct node* temp;
    struct node* last_right_turn=NULL;
    temp=node_finder(data,root,&last_right_turn);
    struct node* first_node=first_node_finder(root);
    if(data!=first_node->data){
        if(temp->left!=NULL){
            struct node* predecessor=maximum_node_from_subtree(temp->left);
            temp->left=predecessor;
            temp->lthreaded=1;
        }
        else{
            temp->left=last_right_turn;
            temp->lthreaded=1;
        }
    }

}

struct node* first_node_finder(struct node* p){
    while (p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}

struct node* node_finder(int data,struct node* p,struct node** last_right){
    
    while(p->data!=data){
        if(data<p->data){
            p=p->left;
        }
        else{
            *(last_right)=p;
            p=p->right;
        }
    }
    return p;
}

struct node* maximum_node_from_subtree(struct node* p){
    while(p->right!=NULL){
        p=p->right;
    }
    return p;
}

void lthreading(struct node* p){
    if(p==NULL){
        printf("Tree is Empty\n");
    }
    if (p->left!=NULL){
        if (p->lthreaded==0){
        lthreading(p->left);
        }
    }
    if (p->left==NULL && p->lthreaded==0){
        inorder_predecessor(p->data);
    }
    if (p->right!=NULL){
        if (p->rthreaded==0){
        lthreading(p->right);
        }
    }
    return;
}

//right node
void rthreading(struct node* p){
    if(p==NULL){
        printf("Tree is Empty\n");
    }
    if (p->left!=NULL){
        if (p->lthreaded==0){
        rthreading(p->left);
        }
    }
    if (p->left==NULL && p->rthreaded==0){
        printf("naman: %d\n",p->data);
        inorder_successor(p->data);
    }
    if (p->right!=NULL){
        if (p->rthreaded==0){
        rthreading(p->right);
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
        temp->rthreaded=1;
    }
    else{
        temp->right=last_left_turn;
        temp->rthreaded=1;
    }
    }
}

struct node* least_node_from_subtree(struct node* p){
    
    while(p->left!=NULL){
        p=p->left;
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