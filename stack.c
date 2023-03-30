#include <stdio.h>
#include <stdlib.h>
#define max 5

int arr[max];
int top = -1;

void push();
void pop();
void peep();
void display();

void main()
{
    int ch;

    printf("\n* * * STACK ADT * * *\n");
    printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\n");

    while (1)
    {
        printf("\nEnter your choice:\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("\nEnter valid choice!\n");
        }
    }
}

void push()
{
    if (top == max - 1)
    {
        printf("\nStack Overflow!\n");
        return;
    }

    top++;
    printf("Enter your element:\t");
    scanf("%d", &arr[top]);
    printf("%d element pushed!\n", arr[top]);
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
        return;
    }

    int ele;
    ele = arr[top];
    top--;
    printf("%d element popped!\n", ele);
}

void peep()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
        return;
    }
    printf("Element at the top is %d\n", arr[top]);
}

void display()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
        return;
    }

    printf("\nElements in the stack are:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\t", arr[i]);
}
