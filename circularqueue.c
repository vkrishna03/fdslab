#include <stdio.h>
#include <stdlib.h>
#define max 5

int cqueue[max];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

void main()
{
    int ch;

    printf("\n* * * Circular Queue ADT* * *\n");
    printf("1.Enqueue\n2.Dequeue\n3.3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter your choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

void enqueue()
{
    if ((front == 0 && rear == max - 1) || (rear == front - 1))
    {
        printf("Circular Queue Overflow!\n");
        return;
    }

    if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else if (rear == max - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    printf("Enter element:\t");
    scanf("%d", &cqueue[rear]);

    printf("%d value inserted!\n", cqueue[rear]);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow!\n");
        return;
    }

    if ((front == max - 1) && front != rear)
    {
        front = 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    printf("Element dequeued!\n");
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Underflow!\n");
        return;
    }

    if (front < rear)
    {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", cqueue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Circular Queue elements are\n");
        for (i = front; i <= max - 1; i++)
        {
            printf("%d\t", cqueue[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d\t", cqueue[i]);
        }
        printf("\n");
    }
}