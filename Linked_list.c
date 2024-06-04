#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* head;

//void create();
void count_and_display();
void insert_at_end();
void insert_at_beginning();
void insert_any_position();
void delete_first();
void delete_last();
void delete_any_position();

int main()
{
int choice;
        while(1){
               
                printf("\n                MENU                             \n");
                printf("\n 1.Create\n");
                printf("\n 2.Display\n");
                printf("\n 3.Insert at the beginning\n");
                printf("\n 4.Insert at the end\n");
                printf("\n 5.Insert at specified position\n");
                printf("\n 6.Delete from beginning\n");
                printf("\n 7.Delete from the end\n");
                printf("\n 8.Delete from specified position\n");
                printf("\n 9.Exit\n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        //create();
                                        break;
                        case 2:
                                        count_and_display();
                                        break;
                        case 3: 
                                        insert_at_beginning();
                                        break;
                        case 4:
                                        insert_at_end();
                                        break;
                        case 5:
                                        insert_any_position();
                                        break;
                        case 6:
                                        delete_first();
                                        break;
                        case 7:
                                        delete_last();
                                        break;
                        case 8:
                                        delete_any_position();
                                        break;
                        
                        case 9:
                                        printf("Exitted\n");
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}


void count_and_display()
{
    struct node *ptr=head;
    int count=0;
    if(ptr==NULL)
    {
        printf("Linked list is empty\n");
    }
    printf("The elements of linked list are:\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        count=count +1;
        ptr=ptr->link;
    }
    printf("The no of elements is %d\n",count);
}


void insert_at_beginning()
{
    struct node* temp=malloc(sizeof(struct node));
    printf("Enter data to insert at beginning\n");
    scanf("%d",&temp->data);
    if(head==NULL)
    {
        temp->link=NULL;
        head=temp;
    }
    else
    {
        temp->link=head;
        head=temp;
    }
}


void insert_at_end()
{
    struct node *ptr,*temp;
    temp=malloc(sizeof(struct node));
    ptr=head;
    printf("Enter data to insert at end\n");
    scanf("%d",&temp->data);
    if(ptr==NULL)
    {
        temp->link=NULL;
        head->data=temp->data;
    }
    else
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    temp->link=NULL;
}


void insert_any_position()
{
    int n;
    struct node*temp=malloc(sizeof(struct node));
    struct node*ptr=head;
    printf("Enter the position where node is to be inserted:\n");
    scanf("%d",&n);
    printf("Enter the data to be inserted:\n");
    scanf("%d",&temp->data);
    if(n<0)
    {
        printf("Indexing starts from 1.Enter valid position\n");
    }
    else if(n==1)
        {
                temp->link=head;
                head=temp;
        }
        else
        {
            for(int i=1;i<n-1;i++)
            {
                ptr=ptr->link;
            }
            temp->link=ptr->link;
            ptr->link=temp;
        }
}


void delete_first()
{
    struct node*ptr=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        head=head->link;
        printf("Deleted item is %d\n",ptr->data);
        free(ptr);
        ptr=NULL;
    }
}


void delete_last()
{
    struct node*ptr=head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted item is %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        printf("Deleted item is %d\n",(ptr->link)->data);
        free(ptr->link);
        ptr->link=NULL;
    }
}


void delete_any_position()
{
    int n;
    struct node*temp1=head;
    struct node*temp2=head;
    printf("Enter the position where node is to be deleted:\n");
    scanf("%d",&n);
    if(n<0)
    {
        printf("Indexing starts from 1.Enter valid position\n");
    }
    else if(n==1)
    {
        printf("Deleted item is:%d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        for(int i=1;i<n-1;i++)
        {
            temp1=temp1->link;
            temp2=temp1;
        }
        temp2=temp2->link;
        temp1->link=temp1->link->link;
        printf("The deleted element is %d\n",&temp2->data);
        free(temp2);
        temp2->link=NULL;
        temp2=NULL;
        
    }
}
