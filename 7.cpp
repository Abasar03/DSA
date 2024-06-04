// Doubly Linked list implementation

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;//POINTER TO HEAD NODE
struct Node* GetNewNode(int x)
{
     struct Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;   
}
void insertathead(int x)
{
    struct Node* newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
}
int main()
{

}