#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head;

void create();
void insert_begin();
void insert_random();
void insert_end();
void delete_begin();
void delete_random();
void delete_end();
void display();

int main()
{
    int ch;

    printf("\n* * * LINKED LIST ADT * * *\n");
    printf("\n1.Create\n2.Insert at beginning\n3.Insert at random\n4.Insert at end.\n5.Delete at beginning\n6.Delete at random\n7.Delete at end\n8.Display\n9.Exit");

    while (1)
    {

        printf("\nEnter your choice:\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_random();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_random();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}

void create()
{
    struct node *ptr, *cptr;
    int c;

    ptr = malloc(sizeof(struct node));
    printf("\nEnter first node info:\t");
    scanf("%d", &ptr->data);
    head = ptr;

    printf("Enter 0 or 1 for more nodes:\t");
    scanf("%d", &c);

    while (c)
    {
        cptr = malloc(sizeof(struct node));

        ptr->link = cptr;
        ptr = cptr;

        printf("Enter node data:\t");
        scanf("%d", &cptr->data);

        printf("Enter 0 or 1 for more nodes:\t");
        scanf("%d", &c);
    }
    ptr->link = NULL;
}

void insert_begin()
{
    struct node *ptr;
    ptr = malloc(sizeof(struct node));

    printf("Enter node data:\t");
    scanf("%d", &ptr->data);

    ptr->link = head;
    head = ptr;
}

void insert_random()
{

    struct node *ptr, *cptr;
    int d;

    ptr = malloc(sizeof(struct node));
    printf("Enter node to be inserted:\t");
    scanf("%d", &ptr->data);

    printf("Enter node info to be inserted after:\t");
    scanf("%d", &d);

    cptr = head;

    while (cptr->data != d)
        cptr = cptr->link;

    ptr->link = cptr->link;
    cptr->link = ptr;
}
void insert_end()
{
    struct node *ptr, *cptr;

    ptr = malloc(sizeof(struct node));
    printf("Enter node to be inserted:\t");
    scanf("%d", &ptr->data);

    cptr = head;

    while (cptr->link != NULL)
        cptr = cptr->link;

    cptr->link = ptr;
    ptr->link = NULL;
}
void delete_begin()
{
    struct node *ptr;

    if (head == NULL)
        printf("Linked list empty!\n");
    else
    {
        ptr = head;
        head = ptr->link;
        free(ptr);
    }
}
void delete_random()
{
    struct node *ptr, *cptr;
    int d;

    if (head == NULL)
    {
        printf("Linked List Underflow!\n");
    }
    else
    {
        printf("Enter node info to be deleted:\t");
        scanf("%d", &d);

        cptr = head;

        while (cptr->data != d)
        {
            ptr = cptr;
            cptr = cptr->link;
        }

        ptr->link = cptr->link;
        free(cptr);
    }
}
void delete_end()
{
    struct node *cptr;

    if (head == NULL)
    {
        printf("Linked List Underflow!\n");
    }
    else
    {
        cptr = head;

        while (cptr->link != NULL)
        {
            cptr = cptr->link;
        }

        cptr->link = NULL;
        free(cptr);
    }
}
void display()
{
    struct node *cptr;
    cptr = head;

    if (head == NULL)
    {
        printf("\nLinked List empty!\n");
    }
    else
    {
        while (cptr != NULL)
        {
            printf("%d -> ", cptr->data);
            cptr = cptr->link;
        }
    }
}