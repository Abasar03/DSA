//Inserting a node at beginning

#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
struct Node* head;
void insert(int x)
{
    Node* temp = new Node();
    temp->data =x;
    temp->next = head;//when list not empty linking one node to another making as head and then to head
    head=temp;//temp address in head
}
void print()
{
    struct Node* temp =head;
    printf("list is\n");
    while (temp != NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
     
}
int main()
{
    head=NULL;//list is empty
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d\n",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter number\n");
        scanf("%d\n",&x);
        insert(x);
        print();
}
    
    return 0;
}
/* if head was used as a local variable in main then
its address was passed in print and insert function as an argument 
and no temporary variable was required and can be used with the same function parameter...
*/