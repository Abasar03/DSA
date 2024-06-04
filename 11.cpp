// Reverse a linked list using stack

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
struct Node* head;
class Stack
{
    private:
        char A[101];
        int top;
    public:
        void push(int x);
        void pop();
        int Top();
        bool isempty();
};

void reverse()
{
    if (head == NULL)
    {
        return;
    }
    stack<struct Node*> S;
    Node* temp = head;
    while (temp!=NULL)
    {
        S.push(temp);
        temp = temp->next;
    }
        temp = S.top();
        head = temp;
        S.pop();
        while (!S.empty())
        {
            temp->next = S.top();
            S.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        
}

void print()
{
    struct Node* temp;
    while (temp != NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
print();cout<<endl;
print();cout<<endl;
print();cout<<endl;
print();cout<<endl;
print();cout<<endl;
    reverse();
    return 0;

}
