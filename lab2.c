#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void enqueue();
void dequeue();
void display_1stelements();
void display_allelements();
int rear=-1;
int queue[maxsize];
int front=0;
int item;

int main(){
    int choice;
    int continuee=1;
    
    while(continuee){
        printf("Menu:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display first element\n4.Display all element\n");
        scanf("%d\n",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
        dequeue();
        break;
        case 3:
        display_1stelements();
        break;
        case 4:
        display_allelements();
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
void enqueue(){
     if (rear>=maxsize-1)
     {
        printf("Queue is full\n");
     }
     else{
        rear=rear+1;
        printf("Enter element\n");
        scanf("%d",&item);
        queue[rear]=item;
     }

}
void dequeue(){
    if (front>rear)
    {
        printf("Queue is empty\n");
    }
    else{
        item=queue[front];
        printf("Dequed item is %d\n",item);
        front=+1;
    }
    
}
void display_1stelements(){
    printf("front elemnt is %d\n",queue[front]);
}
void display_allelements(){
    int i;
    for (int i = front; i<=rear; i++)
    {
        printf("%d",queue[i]);
    }
    printf("\n");
    if (rear==-1)
    {
        printf("Queue is empty\n");
    }
    
}