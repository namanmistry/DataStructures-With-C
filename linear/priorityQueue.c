#include <stdio.h>

#include <stdlib.h>

//Declaring Prototypes

void Append();

void AddAtBegin();

void Display();

void AddAfter();

void Delete1();

int Length();

void Swap(int, int);

void Sort();

void Ascending();

void Descending();

void Reverse();

int value(int);

//Global Variables

struct node
{

    int data;
    int pri;
    struct node *link;
};
int ch1, ch2;

struct node *root = NULL;

//Start Of Definations Of Functions

void main()
{

    int control = 1, choice;

    while (control)
    {

        printf("Enter Your Choice\n");

        printf("1.Insertion\n");

        printf("2.Deletetion\n");

        printf("3.Display All elements\n");

        printf("4.Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            Insertion();

            break;

        case 2:
            Deletion();

            break;

        case 3:
            Display();

            break;

        case 4:
            control = 0;

            break;

        default:
            printf("You Entered Wrong Choice\n");
        }
    }
}

void Insertion()
{

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (root == NULL)
    {
        printf("Enter The Node Data: ");
        scanf("%d", &temp->data);
        printf("Enter the priority\n");
        scanf("%d",&temp->pri);
        temp->link = NULL;
        root = temp;
       
    }

    else
    {

        struct node *p;

        p = root;

        while (p->link != NULL)
        {

            p = p->link;
        }

        p->link = temp;

        printf("Enter The Node Data: ");

        scanf("%d", &temp->data);
        printf("Enter the priority\n");
        scanf("%d",&temp->pri);
        temp->link = NULL;
        Ascending();
    }
}

void Display()
{

    if (root != NULL)
    {

        struct node *temp;

        temp = root;

        while (temp->link != NULL)
        {

            printf("Your Element is %d and priority is %d\n", temp->data,temp->pri);

            temp = temp->link;
        }

        printf("Your Element is %d and priority is %d\n", temp->data,temp->pri);
    }

    else
    {

        printf("Queue Is Already Empty\n");
    }
}






int Length()
{

    struct node *temp;

    temp = root;

    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

void Deletion()
{
    int selection, count1 = 1, count2 = 1, count3 = 1;
    struct node *p, *q;
    p = root;
    q = root;
    if(root!=NULL){
        if (root->link != NULL)
        {
            struct node *temp;
            temp = root;
            temp = temp->link;
            root->link = NULL;
            root = temp;
        }
        else
        {
            root = NULL;
        }
    }
    else{
        printf("Queue Is Already Empty\n");
    }
    }
    


void Swap(int ch1, int ch2)
{
    printf("that:%d %d\n", ch1, ch2);
    if (ch1 - ch2 == 1 || ch1 - ch2 == -1)
    {
        if (ch1 == 1 || ch2 == 1)
        {
            struct node *temp, *p;
            temp = root;
            root = root->link;
            p = root->link;
            root->link = temp;
            temp->link = p;
        }
        else if (ch1 == Length() || ch2 == Length())
        {
            struct node *temp, *p, *q, *q1;
            p = root;
            q = root;
            q1 = root;
            int count = 1, count1 = 1, count2 = 1;
            while (count < Length())
            {
                p = p->link;
                count++;
            }
            while (count1 < Length() - 1)
            {
                q = q->link;
                count1++;
            }
            while (count2 < Length() - 2)
            {
                q1 = q1->link;
                count2++;
            }
            q1->link = p;
            p->link = q;
            q->link = NULL;
        }
        else
        {
            int count = 1, count1 = 1, count2 = 1, count3 = 1;
            struct node *temp, *p, *q, *p1, *q1;
            p = root;
            q = root;
            p1 = root;
            q1 = root;
            while (count < ch1)
            {
                p = p->link;
                count++;
            }
            while (count1 < ch2)
            {
                q = q->link;
                count1++;
            }
            while (count2 < ch1 - 1)
            {
                p1 = p1->link;
                count2++;
            }
            while (count3 < ch2 + 1)
            {
                q1 = q1->link;
                count3++;
            }
            temp = p;
            p1->link = p->link;
            q->link = temp;
            p->link = q1;
            printf("Hello\n");
        }
    }
    else if (ch1 - ch2 == Length() - 1 || ch1 - ch2 == 1 - Length())
    {
        struct node *temp, *p, *q, *p2;
        p = root;
        q = root;
        p2 = root;
        int count = 1, count1 = 1, count2 = 1;
        while (count < Length())
        {
            p = p->link;
            count++;
        }
        while (count1 < Length() - 1)
        {
            q = q->link;
            count1++;
        }
        while (count2 < 2)
        {
            p2 = p2->link;
            count2++;
        }
        temp = root;
        p->link = root->link;
        root = p;
        q->link = temp;
        temp->link = NULL;
    }
    else
    {
        if (ch1 == 1 || ch2 == 1)
        {
            struct node *p, *temp, *p1, *p2, *q1, *temp1;
            temp = root;
            p1 = root;
            p = root;
            p2 = root;
            q1 = root;
            int count = 1, count1 = 1, count2 = 1, count3 = 1;
            if (ch1 == 1)
            {
                while (count < ch2)
                {
                    p = p->link;
                    count++;
                }
                while (count1 < ch2 - 1)
                {
                    p1 = p1->link;
                    count1++;
                }
                while (count2 < ch2 + 1)
                {
                    p2 = p2->link;
                    count2++;
                }
                
                temp = root;
                temp1 = root->link;
                root = p;
                p->link = temp1;
                p1->link = temp;
                temp->link = p2;
            }
            else
            {
                while (count < ch1)
                {
                    p = p->link;
                    count++;
                }
                while (count1 < ch1 - 1)
                {
                    p1 = p1->link;
                    count1++;
                }
            }
        }
        else
        {
            struct node *temp, *p, *q, *p1, *p2, *q1, *q2;
            p = root;
            q = root;
            p1 = root;
            p2 = root;
            q1 = root;
            q2 = root;
            int count = 1, count1 = 1, count2 = 1, count3 = 1, count4 = 1, count5 = 1;
            while (count < ch1)
            {
                p = p->link;
                count++;
            }
            while (count1 < ch2)
            {
                q = q->link;
                count1++;
            }
            while (count2 < ch1 - 1)
            {
                p1 = p1->link;
                count2++;
            }
            while (count3 < ch2 - 1)
            {
                q1 = q1->link;
                count3++;
            }

            while (count4 < ch1 + 1)
            {
                p2 = p2->link;
                count4++;
            }

            while (count5 < ch2 + 1)
            {
                q2 = q2->link;
                count5++;
            }

            p1->link = q1->link;
            q->link = p2;
            q1->link = p;
            p->link = q2;
        }
    }
}

void Ascending()
{

    for (int i = 1; i <= Length() - 1; i++)
    {
        for (int j = i + 1; j <= Length(); j++)
        {
            if (value(i) > value(j))
            {

                Swap(i, j);
            }
        }
    }
}

int value(int i)
{

    struct node *temp;
    temp = root;
    int count = 1;
    while (count < i)
    {
        temp = temp->link;
        count++;
    }
    return temp->pri;
}

//End OF Declaration OF Functions
