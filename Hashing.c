#include<stdio.h>
#include <stdlib.h>
int n, m;
int *ht;
int count = 0;
void insert(int key)
{
    int index = key % m;
    while (ht[index] != -1)
    {
        index = (index + 1) % m;
    }
    ht[index] = key;
    count++;
}
void display()
{
    int i;
    if (count == 0)
    {
        printf("\nHash table is empty");
        return;
    }
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++)
    {
        printf("T[%d] --> %d\n", i, ht[i]);
    }
}
int main()
{
    int i, key;
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);
    printf("\nEnter the memory locations (m) for hash table: ");
    scanf("%d", &m);
    ht = (int *)malloc(m*sizeof(int));
    for (i = 0; i < m; i++)
        ht[i] = -1;
    for (i = 0; i < n; i++)
    {
        if (count == m)
        {
            printf("\nHash table is full. Cannot insert more records.");
            break;
        }
        printf("Enter key for record %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
