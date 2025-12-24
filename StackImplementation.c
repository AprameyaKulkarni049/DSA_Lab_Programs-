#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
struct node *create(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}
void push(int val)
{
    struct node *newnode;
    newnode=create(val);
    newnode->next=head;
    head=newnode;
}
void pop()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Stack is empty");
    }
    head=head->next;
    printf("Node popped: %d",temp->data);
    free(temp);
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d \n",temp->data);
        temp=temp->next;
    }
}
void main()
{
    int val,choice;
    while(1)
    {
        printf("\nStack using Linked list");
        printf("\n1.Push 2.Pop 3.Display 4.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter value: ");
                scanf("%d",&val);
                push(val);
                break;
            }
        case 2:
            {
                pop();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                printf("Exiting....");
                exit(0);
            }
        }
    }
}
