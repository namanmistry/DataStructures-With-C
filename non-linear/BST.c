#include <stdio.h>
#include <stdlib.h>
//Declaring node structure
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL, *temp = NULL, *big_data_address = NULL, *big_data_parent_address = NULL;
int data, delete_data, big_data = 0;
struct node *target, *target_parent;
char parent_side, big_data_parent_side;
//Prototypes of functions
void insert();
void insertion_traversal(struct node*);
void traversal();
void pre_order(struct node*);
void in_order(struct node*);
void post_order(struct node*);
void delete_node_finder(struct node*);
void delete();
void big_data_finder(struct node*);

void main()
{
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
            traversal();
            break;
        case 3:
            printf("Enter data: \n");
            scanf("%d", &delete_data);
            delete ();

            break;
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
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: \n");
    scanf("%d", &data);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        insertion_traversal(root);
    }
}

void insertion_traversal(struct node *ptr)
{
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

void traversal()

{
    int choice,control=1;

    while (control)
    {
        printf("Enter Your Choice: \n");
        printf("1.pre_order\n");
        printf("2.in_order\n");
        printf("3.post_order\n");
        printf("4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            pre_order(root);
            break;

        case 2:
            in_order(root);
            break;

        case 3:
            post_order(root);
            break;

        case 4:
            control= 0;
            break;

        default:
            break;
        }
    }
}

void pre_order(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    if (ptr != NULL)
    {
        printf("Element is: %d\n", ptr->data);
    }
    if (ptr->left != NULL)
    {
        pre_order(ptr->left);
    }
    if (ptr->right != NULL)
    {
        pre_order(ptr->right);
    }
    return;
}
void in_order(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    if (ptr->left != NULL)
    {
        in_order(ptr->left);
    }
    if (ptr != NULL)
    {
        printf("Element is: %d\n", ptr->data);
    }
    if (ptr->right != NULL)
    {
        in_order(ptr->right);
    }
    return;
}
void post_order(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    if (ptr->left != NULL)
    {
        post_order(ptr->left);
    }
    if (ptr->right != NULL)
    {
        post_order(ptr->right);
    }
    if (ptr != NULL)
    {
        printf("Element is: %d\n", ptr->data);
    }
    return;
}

void delete_node_finder(struct node *ptr)
{
    if (ptr->left != NULL)
    {
        delete_node_finder(ptr->left);
    }
    if (ptr != NULL)
    {
        if (ptr->data == delete_data)
        {
            target = ptr;
        }
        if (ptr->left != NULL)
        {
            struct node *temp1;
            temp1 = ptr->left;
            if (temp1->data == delete_data)
            {
                target_parent = ptr;
                parent_side = 'l';
            }
        }
        if (ptr->right != NULL)
        {
            struct node *temp2;
            temp2 = ptr->right;
            if (temp2->data == delete_data)
            {
                target_parent = ptr;
                parent_side = 'r';
            }
        }
    }
    if (ptr->right != NULL)
    {
        delete_node_finder(ptr->right);
    }
    return;
}

void delete ()
{
    if (delete_data == root->data)
    {

        root = NULL;
        return;
    }
    delete_node_finder(root);
    //To delete leaf node
    if (target->left == NULL && target->right == NULL)
    {
        if (parent_side == 'l')
        {
            target_parent->left = NULL;
        }
        else if (parent_side == 'r')
        {
            target_parent->right = NULL;
        }
    }
    //To delete node with one leaf
    else if ((target->left == NULL && target->right != NULL) || (target->left != NULL && target->right == NULL))
    {
        if (parent_side == 'l')
        {
            if (target->left != NULL)
            {
                target_parent->left = target->left;
            }
            else if (target->right != NULL)
            {
                target_parent->left = target->right;
            }
        }
        else if (parent_side == 'r')
        {
            if (target->left != NULL)
            {
                target_parent->right = target->left;
            }
            else if (target->right != NULL)
            {
                target_parent->right = target->right;
            }
        }
    }
    //To delete node with two child
    else if (target->left != NULL && target->right != NULL)
    {
        big_data_finder(target->left);

        if (parent_side == 'l')
        {

            if ((big_data_address->right == NULL && big_data_address->left != NULL) || (big_data_address->right != NULL && big_data_address->left == NULL))
            {
                target_parent->left = big_data_address;
                big_data_address->right = target->right;
            }
            else if (big_data_address->left == NULL && big_data_address->right == NULL)
            {
                target_parent->left = big_data_address;
                big_data_address->right = target->right;
            }
            else
            {
                target_parent->left = big_data_address;
                big_data_address->right = target->right;
                big_data_address->left = target->left;
                if (big_data_parent_side == 'l')
                {
                    big_data_parent_address->left = NULL;
                }
                else if (big_data_parent_side == 'r')
                {
                    big_data_parent_address->right = NULL;
                }
            }
        }
        else if (parent_side == 'r')
        {

            if ((big_data_address->right == NULL && big_data_address->left != NULL) || (big_data_address->right != NULL && big_data_address->left == NULL))
            {
                target_parent->right = big_data_address;
                big_data_address->right = target->right;
            }
            else if (big_data_address->left == NULL && big_data_address->right == NULL)
            {
                target_parent->right = big_data_address;
                big_data_address->right = target->right;
            }
            else
            {
                target_parent->right = big_data_address;
                big_data_address->right = target->right;
                big_data_address->left = target->left;
                if (big_data_parent_side == 'l')
                {
                    big_data_parent_address->left = NULL;
                }
                else if (big_data_parent_side == 'r')
                {
                    big_data_parent_address->right = NULL;
                }
            }
        }
    }
}

void big_data_finder(struct node *ptr)
{
    if (ptr->left != NULL)
    {
        big_data_finder(ptr->left);
    }
    if (ptr != NULL)
    {
        if (big_data < ptr->data)
        {
            big_data_address = ptr;
            big_data = ptr->data;
        }
    }
    if (ptr->right != NULL)
    {
        big_data_finder(ptr->right);
    }
    if (ptr->left != NULL)
    {
        struct node *temp1;
        temp1 = ptr->left;
        if (temp1->data == big_data)
        {
            big_data_parent_address = ptr;
            big_data_parent_side = 'l';
        }
    }
    if (ptr->right != NULL)
    {
        struct node *temp2;
        temp2 = ptr->right;
        if (temp2->data == big_data)
        {
            big_data_parent_address = ptr;
            big_data_parent_side = 'r';
        }
    }

    return;
}