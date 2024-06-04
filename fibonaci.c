#include <stdio.h>
int main() {
  int t1 = 0, t2 = 1, nextTerm = 0,sum=0, n;
  printf("Enter a positive number: ");
  scanf("%d", &n);
  printf("Fibonacci Series:");
 
 for (int i=0;i<n;i++) {
    printf("%d, ", nextTerm);
    sum=sum+nextTerm;
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
    
  }
  printf("Sum is %d",sum);
 
  return 0;
 
}
 