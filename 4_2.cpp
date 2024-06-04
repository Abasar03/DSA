 //Reversing a linked list using iterative method

#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
struct Node* head;
void print()
{
    struct Node* temp =head;
    while (temp != NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
void insert(int data,int n)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (n==1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 0; i<n-2; i++)
    {
        temp2= temp2->next;
    }
    temp1->next = temp2->next;
    temp2 ->next = temp1;
}
void reverse()
{
    struct Node *current,*prev,*next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
        head = prev;
    
} 
int main(){
    head = NULL;//EMPTY LIST
    insert(2,1);
    insert(3,2);
    insert(4,3);
    insert(1,4);
    insert(5,5);
    print();
    reverse();
    print();
    return 0;
}