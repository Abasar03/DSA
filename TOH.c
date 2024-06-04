#include<stdio.h>
#include<stdlib.h>
void transfer(int n, char from, char to, char temp);
 
int main()
{
    int n;
 
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    transfer(n, 'A', 'C', 'B');
    return 0;
}
void transfer(int n, char from, char to, char temp)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", from, to);
        return;
    }
    else
    {
    transfer(n - 1, from, temp , to);
    printf("\n Move disk %d from tower %c to tower %c", n, from, to);
    transfer(n - 1, temp, to, from);
    }
}