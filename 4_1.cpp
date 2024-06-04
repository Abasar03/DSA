 //Reversing a linked list

#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
struct Node* head;
void print(struct Node* head)
{
    struct Node* temp =head;
    while (temp != NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
struct Node* insert(int data,int n)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if (n==1)
    {
        temp1->next = head;
        head = temp1;
        return 0;
    }
    Node* temp2 = head;
    for (int i = 0; i<n-2; i++)
    {
        temp2= temp2->next;
    }
    temp1->next = temp2->next;
    temp2 ->next = temp1;
}
struct Node* reverse(struct Node* head)
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
        return head;
    
} 
int main(){
    head = NULL;//EMPTY LIST
    head = insert(2,1);
    head = insert(3,2);
    head = insert(4,3);
    head = insert(1,4);
    head = insert(5,5);
    print(head);
    // head = reverse(head);
    // print(head);
    return 0;
}