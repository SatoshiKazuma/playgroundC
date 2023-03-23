#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} Node;

Node *insert(int item, Node *root)
{
    Node *temp, *cur, *prev;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    if (root == NULL)
    {
        return temp;
    }
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        if (cur->data == item)
        {
            printf("\nduplicate\n");
            return root;
        }
        prev = cur;
        if (item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (item <= prev->data)
        prev->left = temp;
    else
        prev->right = temp;
    return root;
}

Node *constructBST()
{
    Node *root = NULL;
    printf("\nEnter no of elements: ");
    int n, item;
    scanf("%d", &n);
    printf("\nEnter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = insert(item, root);
    }
    printf("\nConstruction Successful.\n");
    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

void main()
{
    Node *root;
    int choice;
    while (1)
    {
        printf("\n1.INSERT\t2.PREORDER\t3.INORDER\t4.POSTORDER\t5.EXIT\nCHOICE: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nINSERT\n");
            root = constructBST();
            break;
        case 2:
            printf("\n preorder\n");
            preorder(root);
            break;
        case 3:
            printf("\n inorder\n");
            inorder(root);
            break;
        case 4:
            printf("\n postorder\n");
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
}