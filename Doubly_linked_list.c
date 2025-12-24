#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

struct node* create(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
int count()
{
    int c = 0;
    struct node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        c++;
    }
    return c;
}
void insert_left(int val, int pos)
{
    int n = count();
    struct node *newnode = create(val);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    newnode->next = temp;
    newnode->prev = temp->prev;

    temp->prev->next = newnode;
    temp->prev = newnode;
}
void del_val(int val) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL && temp->data != val)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}
void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, val, pos;

    while (1) {
        printf("\n1. Insert left of position\n2. Delete value\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Insert left of position: ");
                scanf("%d", &pos);
                insert_left(val, pos);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                del_val(val);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
