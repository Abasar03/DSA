#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front = 0;
int rear = -1;
int item;


void enqueue();
int dequeue();
void display();
int displayNumberOfElements();
int display_front_element();
 
int main()
{
    while(1)
    {
        printf("Enter 1 to add new element \nEnter 2 to delete element \nEnter 3 to display element on the front \n");
        printf("Enter 4 to display element \nEnter 5 to display number of element\nEnter 6 to exit\n");
        int n;
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("The first element is %d\n", display_front_element());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("The no of elemenmts is %d\n", displayNumberOfElements());
            break;
        case 6:
            printf("Exitted");
            exit(0);
        default:
            printf("You have entered invalid.\n");
            break;
        }
    }
    return 0;
}
 
void enqueue()
{
    if(rear>= size - 1)
    {
        printf("Queue is full\n");
        return;
    }
    rear=rear+1;
    printf("Enter element to add :" );
    scanf("%d", &queue[rear]);
    //scanf("%d", &item);
    //queue[rear]=item;
}
 
int dequeue()
{
    if(rear==-1)
    {
        printf("Empty queue\n");
        return 0;
    }
    printf("The deleted item is %d\n",queue[front]);
    return front=front+1;
}
 
int display_front_element()
{
    if(rear == -1)
    {
        printf("Empty queue\n");
        return 0;
    }
    return queue[front];
}
 
void display()
{
    if(rear == -1)
    {
        printf("Empty queue\n");
    }
    printf("The elements are:\n");
    for(int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}
 
 
int displayNumberOfElements()
{
    return rear+1;
}