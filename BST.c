#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int val)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
struct node *insert(struct node *root,int val)
{
    if(root==NULL)
    {
        return create(val);
    }
    if(val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=insert(root->right,val);
    }
    return root;
};
struct node *bst_min(struct node *ptr)
{
    struct node *current=ptr;
    while(current&&current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}
struct node *del(struct node *root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key<root->data)
    {
        root->left=del(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=del(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp = bst_min(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
        }
        return root;
}
void display(struct node *root)
{
    printf("Tree elements by inorder traversal: ");
    inorder(root);
    printf("\n");
}
int main()
{
    struct node* root = NULL;
    int choice, value;
    do {
    printf("\n--- Binary Search Tree Menu ---\n");
    printf("1. Construct/Insert element\n");
    printf("2. Traverse (In-order, Pre-order, Post-order)\n");
    printf("3. Display elements\n");
    printf("4. Delete an element\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("In-order traversal: ");
            inorder(root);
            printf("\n");
            printf("Pre-order traversal: ");
            preorder(root);
            printf("\n");
            printf("Post-order traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 3:
            display(root);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = del(root, value);
            printf("Node deleted if present.\n");
            break;

        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
