//Inserting a node at nth position

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
class Node{
public:
int data;
class Node* next;
};
class Node* head;
void print()
{
    class Node* temp =head;
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
int main(){
    head = NULL;//EMPTY LIST
    insert(3,1);
    insert(2,2);
    insert(4,3);
    insert(1,4);
    insert(5,5);
    print();
    return 0;
}