//Stack implementation using linked list
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* link;
};
struct Node* Top = NULL;
void push(int x)
{
    struct Node* temp = new Node();
    temp->data = x;
    temp->link = Top;
    Top = temp;
    
}
void pop()
{
    struct Node* temp;
    if (Top == NULL)
    {
        return;
    }
    temp=Top;
    Top= Top->link;
    free(temp);
}
void print()
{
    struct Node* temp = Top;
    while (temp != NULL)
    {
        printf("%d",temp->data);
        temp=temp->link;
    }
    printf("\n");

}
int main()
{
push(2);print();cout<<endl;
push(5);print();cout<<endl;
push(10);print();cout<<endl;
pop();print();cout<<endl;
push(9999);print();cout<<endl;
    return 0;
}