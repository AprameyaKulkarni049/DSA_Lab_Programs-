#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

struct node1 {
    int data;
    struct node1 *next;
} *head1 = NULL;

struct node* create1(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

struct node1* create2(int val) {
    struct node1* temp = (struct node1*)malloc(sizeof(struct node1));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insert1(int val) {
    struct node *newnode = create1(val);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insert2(int val) {
    struct node1 *newnode = create2(val);

    if (head1 == NULL) {
        head1 = newnode;
        return;
    }

    struct node1 *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void display1() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display2() {
    struct node1 *temp = head1;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void concatenate() {
    struct node *temp = head;
    struct node1 *temp1 = head1;

    printf("\nConcatenated Output:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    while (temp1 != NULL) {
        printf("%d -> ", temp1->data);
        temp1 = temp1->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1.Insert 1st list\n2.Insert 2nd list\n3.Display 1\n4.Display 2\n5.Concatenate\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert1(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insert2(val);
                break;

            case 3:
                display1();
                break;

            case 4:
                display2();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
