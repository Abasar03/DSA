//Printing a linked list using recursion in forward and reverse order

#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
void Print(struct Node* head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    
    else
    {
        printf("%d",head->data);//For reverse printing just interchange two lines.
        Print(head->next);//1st use recursion and print function for reverse printing.
    }

}
struct Node* insert(Node* head,int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL )
    {
        head = temp;
    
    }
    else
    {
        Node* temp1 = head;
        while (temp1->next!=NULL)
        {
            temp1=temp1->next;
            temp1->next=temp;  
        }
        
    }
    return head;

}

int main(){
    struct Node* head = NULL;
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    Print(head);
    return 0;
}