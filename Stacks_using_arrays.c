#include<stdio.h>
#include<stdlib.h>
#define max 100
int top=-1;
int A[max],i,n,ele,n,choice;

void push(int ele)
{
    if(top==max-1)
    {
        printf("Stack overflow!!!");
    }
    else
    {
        top=top+1;
        A[top]=ele;
    }
    
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty!!!");
    }
    else
    {
        ele=A[top];
        printf("Popped element: %d",ele);
        top--;
    }
}

void display()
{
    for(i=0;i<=top;i++)
    {
        printf("%d ",A[i]);
    }
}
void main()
{
    printf("Enter the size of the stack: ");
    scanf("%d",&n);
    while(1)
    {
        printf("\nEnter 1.Push 2.Pop 3.Display 4.Exit");
        scanf("\n%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&ele);
            push(ele);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...");
            exit(0);
        default:
            printf("Wrong input");
            break;
        }
    }
}
