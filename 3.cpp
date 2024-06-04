//Deleting a node at nth position

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
    void insert(int x)
{
    Node* temp = new Node();
    temp->data =x;
    temp->next = head;
    head=temp;
}

void delete1(int n)
{
    struct Node* temp1 = head;
    if (n==1)
    {
        head = temp1->next;//head points to 2nd node
        delete temp1;
        return;
    }
    for (int  i = 0; i<n-2; i++)
    {
        temp1=temp1->next;
    }
        //temp1 points to n-1 th node
        struct Node* temp2 = temp1->next;//nth node
        temp1->next=temp2->next;//n+1 th node
        delete temp2;

    
}
int main(){
    head = NULL;//EMPTY LIST
    insert(2);
    insert(3);
    insert(4);
    insert(1);
    insert(5);
    print();
    int n;
    printf("Enter the position to delete\n");
    scanf("%d\n",&n);
    delete1(n);
    print();
    return 0;
}