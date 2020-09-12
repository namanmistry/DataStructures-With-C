#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *head = NULL;

void insert(int);
void delete(int);
void traverse();
void inorder(NODE *);
void preorder(NODE *);
void postorder(NODE *);

NODE *pass(NODE *, NODE *);
NODE *findHigh(NODE *);
NODE *findLow(NODE *);

void main() {
    int opt, val;
    while (opt != 4)
    {
        printf("\n1. Insert \n2. Delete \n3. Traverse \n4. Exit \n");
        scanf("%d" ,&opt);
        switch (opt)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d" ,&val);
                insert(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d" ,&val);
                delete(val);
                break;
            
            case 3:
                traverse();
                break;

            case 4:
                break;  

            default:
                printf("\nEnter valid number\n");
            
        }
    }
}

void insert(int val) {
    NODE *t;
    t = (NODE *)malloc(sizeof(NODE));
    t->data = val;
    t->left = NULL;
    t->right = NULL;

    if(head == NULL) {
        head = t;
    } else {
        NODE *curr, *p;
        curr = head;
        while(curr) {
            p = curr;
            if(t->data > p->data) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        if(t->data > p->data) {
            p->right = t;
        } else {
            p->left = t;
        }
    }
}


void delete(int val) {
    NODE *curr, *p, *xch;
    curr = head;
    while(curr->data != val) {
        p = curr;
        if(val > p->data) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }  
    if(curr->left != NULL || curr->right != NULL){
        xch = pass(curr->left, curr->right); 
        if(xch->data > p->data) {
            p->right = xch;
            if(curr->left != NULL){xch->right = curr->right;}
            else{xch->left = curr->left;}
            free(curr);
        } else {
            p->left = xch;
            if(curr->left != NULL){xch->right = curr->right;}
            else{xch->left = curr->left;}
            free(curr);
        }
    } else {
        if(curr->data > p->data) {
            p->right = NULL;
        } else {
            p->left = NULL;
        }
    }
}

NODE* pass(NODE *LT, NODE *RT) {
    NODE *xch;
    if(LT != NULL) {
        xch = findHigh(LT);
    } else if(RT != NULL) {
        xch = findLow(RT);
    }
    return xch;
}

NODE* findHigh(NODE *LT) {
    NODE *p = NULL, *OLT = LT;
    while(LT->right != NULL) {
        p = LT;
        LT = LT->right;
    }
    if(p != NULL){
        p->right = NULL;
        LT->left = OLT;
    }

    return LT;
}

NODE* findLow(NODE *RT) {
    NODE *p = NULL, *ORT = RT;
    while(RT->left != NULL) {
        p = RT;
        RT = RT->left;
    }
    if(p != NULL){
        p->left = NULL;
        RT->right = ORT;
    }
    return RT;
}

void traverse() {
    if(head == NULL) {
        printf("BST Empty");
    } else {
        int tMethod;
        printf("\n1. InOrder \n2. PreOrder \n3. PostOrder \n");
        scanf("%d" ,&tMethod);
        switch (tMethod)
        {
        case 1:
            inorder(head);
            break;

        case 2:
            preorder(head);
            break;

        case 3:
            postorder(head);
            break;

        default:
            printf("\nEnter valid number\n");
        }
    }
}

void inorder(NODE *t) {
    if(t->left){
        inorder(t->left);
    } 
    printf("\n%d" ,t->data);
    
    if(t->right){
        inorder(t->right);
    }
}

void preorder(NODE *t) {
    printf("\n%d" ,t->data);

    if(t->left) {
        preorder(t->left);
    }

    if(t->right) {
        preorder(t->right);
    }
}

void postorder(NODE *t) {
    if(t->left) {
        postorder(t->left);
    }

    if(t->right) {
        postorder(t->right);
    }

    printf("\n%d" ,t->data);
}