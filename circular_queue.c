#include <stdio.h>
#include <stdlib.h>
#define size 5

int front = -1;
int rear = -1;
int item;
int queue[size];


void enqueue();
void dequeue();
void display_front_element();
void display_all_elements();


int main()
{
    int truee=1;
    while(truee){
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
             display_front_element();
            break;
       case 4:
            display_all_elements();
            break;
        case 5:
            printf("The no of elements are:%d\n",rear+1);
            break;
        case 6:
            truee=0;
            printf("Exitted");
            exit(0);
        default:
            printf("You have entered invalid.\n");
            break;
        }
    }
}

void enqueue()
{

    if ((rear + 1)% size==front)
    {
        printf("Queue is full\n");
    }
    else{
        printf("Enter element in queue\n");
        scanf("%d",&item);
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%size;
        }
        queue[rear] = item;
    }
    
}
    

void dequeue()
{
    if (front ==-1 && rear==-1)
    {
        printf("Queue is empty\n");
    }
    else{
        int x=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front = (front+1)%size;
    }
    printf("Deleted item is %d\n",x);
        
}
}
void display_front_element()
{
    if (front==-1 && rear==-1)
    {
        printf("Empty queue\n");
    }
    
    printf("1st element is %d\n", queue[front]);
}
void display_all_elements()
{
    int i;
    if (front ==-1 && rear==-1)
    {
        printf("Empty queue\n");
    }
    else{
    printf("The elements are:\n");
    for ( i = front; i != rear; i=((i+1)%size))
    {
        printf("%d\n", queue[i]);
    }
    printf("%d\n",queue[i]);
    }
}
