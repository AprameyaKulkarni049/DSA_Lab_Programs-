#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

struct node* create(int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void enqueue(int val) {
    struct node *newnode = create(val);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void dequeue() {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    printf("Node popped: %d\n", temp->data);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int val, choice;

    while (1) {
        printf("\nQueue using Linked List");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
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
