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

    struct node_thread* data;

    struct node *link;
};
int ch1, ch2;

struct node *root = NULL;

//Start Of Definations Of Functions


void Append(struct node_thread* ptr)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (root == NULL)
    {

        temp->data=ptr;

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

        temp->data=ptr;


        temp->link = NULL;
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

            printf("Your Element is: %d\n", temp->data);

            temp = temp->link;
        }

        printf("Your Element is: %d\n", temp->data);
    }

    else
    {

        printf("Linked List Is Already Empty\n");
    }
}

void AddAtBegin()
{

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (root == NULL)
    {

        printf("ENter Node Data: \n");

        scanf("%d", &temp->data);

        root = temp;
    }

    else
    {

        printf("ENter Node Data: \n");

        scanf("%d", &temp->data);

        temp->link = root;

        root = temp;
    }
}

void AddAfter()
{

    int ch, count1 = 1, count2 = 1;

    struct node *temp, *p, *q;

    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Node Data: \n");

    scanf("%d", &temp->data);

    p = root;

    q = root;

    printf("After Which Node You Want To Insert New Node: \n");

    scanf("%d", &ch);

    while (count1 <= ch)
    {

        if (q != NULL)
        {

            q = q->link;
        }

        else
        {

            q->link = temp;

            temp->link = NULL;
        }

        count1++;
    }

    temp->link = q;

    while (count2 < ch)
    {

        p = p->link;

        count2++;
    }

    p->link = temp;
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

void Delete1()
{

    int selection, count1 = 1, count2 = 1, count3 = 1;

    struct node *p, *q;

    p = root;

    q = root;

    printf("Enter The Node That You Want To Delete: \n");

    scanf("%d", &selection);

    if (selection == 1)
    {

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

    else if (selection == Length())
    {

        struct node *temp;

        temp = root;

        int count = 1;

        while (count < Length() - 1)
        {

            temp = temp->link;

            count++;
        }

        temp->link = NULL;
    }

    else if (1 < selection < Length())
    {

        struct node *temp;

        temp = root;

        while (count1 < selection - 1)
        {

            temp = temp->link;

            count1++;
        }

        while (count2 <= selection)
        {

            p = p->link;

            count2++;
        }

        temp->link = p;

        printf("hello this is naman mistry");

        Display();

        printf("%x", temp->link);
    }

    else
    {

        printf("The Node You Want To Delete Does Not Exists\n");
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
            if (value(i) < value(j))
            {

                Swap(i, j);
            }
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
    return temp->data;
}

//End OF Declaration OF Functions
