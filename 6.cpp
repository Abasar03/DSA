//Reverse a linked list using recursion

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void Reverse(struct Node* p) {
    if (p->next == NULL) {
        head = p; // Update the head to the last node (new head)
        return;
    }
    Reverse(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void Insert(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Print() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    
    printf("Original List: ");
    Print();
    
    Reverse(head);
    
    printf("Reversed List: ");
    Print();
    
    return 0;
}
