#include <stdio.h>
#include <stdlib.h>
#define size 5

int front = 0;
int rear = 0;
int item;
int queue[size];

int main()
{
    int choice,continuee=1;

    while (continuee)
    {
        printf("Menu:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display front element\n4.Display all element\n");
        scanf("%d\n", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display_front_element();
            break;
        case 4:
            display_all_elements();
            break;
        case 5:
            continuee=0;
            break;
        default:
            printf("Invalid choice break");
            break;
        }
    }
}

void enqueue()
{
    if ((front == (rear + 1)) % size)
    {
        printf("Queue is full\n");
    }
    else
        printf("Enter element in queue\n");
        scanf("%d",&item);
    queue[rear] = item;
    rear = (rear + 1) % size;
}
void dequeue()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Dequed item is %d\n",queue[front]);
        front = (front+1)%size;
    }
        
}
void display_front_element()
{
    if (front == rear)
    {
        printf("Empty queue\n");
    }
    
    printf("1st element is %d\n", queue[front]);
}
void display_all_elements()
{
    for (int i = front; i != rear; i=(i+1)%size)
    {
        printf("%d\n", queue[i]);
    }
}