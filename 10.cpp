// Reverse a string using stack

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
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

void reverse(char* c,int n)
{
    Stack<char> S;
    //loop for push
    for (int i = 0; i < n; i++)
    {
        S.push(c[i]);
    }
    //loop for pop
    for (int  i = 0; i < n; i++)
    {
        c[i]=S.Top();//overwite the character at i
        S.pop();
    }
    
}

int main()
{
    char c[100];
    printf("Enter a astring");
    gets(c);
    reverse(c,strlen(c));
    printf("Output is %s",c);
    return 0;

}
