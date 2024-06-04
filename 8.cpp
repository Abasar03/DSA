//Stack implementation using array
#include<iostream>
#define maxsize 101;
using namespace std;
int A[101];
int top = -1;
void push(int x)
{
    if (top == 101-1)
    {
        cout<<"Error i.e. stack overflow"<<endl;
        return;
    }
    
    top++;
    A[top]=x;
}
void pop()
{
    if (top == -1)
    {
        cout<<"No elements to pop"<<endl;
    }
    
    top--;

}
int Top()
{
    return A[top];
}
void print()
{
    int i;
    cout<<"Stack"<<endl;
    for ( i = 0; i <= top; i++)
    {
        cout<<A[i]<<endl;
    }
    
}
int main()
{
push(2);print();
push(5);print();
push(10);print();
pop();print();
push(155555);print();
    return 0;
}