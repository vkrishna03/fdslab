#include <stdio.h>
#include <stdlib.h>
#define max 5

int arr[max];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

void main()
{
    int ch;

    printf("\n* * * QUEUE ADT * * *\n");
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice:\t");
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
            printf("\nEnter valid choice!\n");
        }
    }
}

void enqueue()
{
    if (rear == max - 1)
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else
    {
        rear++;
    }

    printf("Enter the element:\t");
    scanf("%d", &arr[rear]);
    printf("%d element inserted!\n", arr[rear]);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    int ele = arr[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    printf("%d element dequeued.\n", ele);
}

void display()
{
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Elements in the queue are\n");
    for (int i = front; i <= rear; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}