#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted\n", value);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("%d deleted\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Queue: ");

        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
