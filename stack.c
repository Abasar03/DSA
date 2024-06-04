#include<stdio.h>
#include<stdlib.h>
#define size 10
int stack[size];
int top = -1;
 

void push();
void pop();
int peek();
void display();
int displayNumberOfElements();

int main()
{
    while(1)
    {
        printf("Enter 1 to add new element \nEnter 2 to delete element \nEnter 3 to display element on the top \n");
        printf("Enter 4 display element \nEnter 5 to display number of element\nEnter 6 to exit\n");
        int n;
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("The element on top is %d\n", peek());
            break;
        case 4:
            printf("The elements are:\n");
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
 
void push()
{
    if(top == size - 1)
    {
        printf("Stack is full\n");
        return;
    }
    top=top+1;
    printf("Enter element to add :" );
    scanf("%d", &stack[top]);
}
 
void pop()
{
    if(top == -1)
    {
        printf("Empty stack\n");
        return;
    }
    top--;
    printf("The deleted item is %d\n",stack[top+1]);
    //return stack[top + 1];
}
 
int peek()
{
    if(top == -1)
    {
        printf("Empty stack\n");
        return 0;
    }
    return stack[top];
}
 
void display()
{
    if(top == -1)
    {
        printf("Empty stack\n");
    }
    for(int i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}
 
 
int displayNumberOfElements()
{
    return top + 1;
}