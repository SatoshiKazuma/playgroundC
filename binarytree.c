#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} Node;
Node *insertLevelOrder(int arr[], int i, int n)
{
    Node *root = NULL;
    if (i <= n)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = arr[i];
        root->left = insertLevelOrder(arr, (2 * i), n);
        root->right = insertLevelOrder(arr, (2 * i) + 1, n);
    }
    return root;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return ((lheight > rheight) ? (lheight + 1) : (rheight + 1));
}

void displayGivenLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        printf(" %d ", root->data);
    }
    else if (level > 1)
    {
        displayGivenLevel(root->left, level - 1);
        displayGivenLevel(root->right, level - 1);
    }
}

void displayLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        displayGivenLevel(root, i);
        printf("\n");
    }
}
void main()
{
    Node *root = NULL;
    printf("Enter node count: ");
    int n;
    scanf(" %d", &n);
    printf("Enter elements: ");
    int a[10];
    for (int i = 1; i <= n; i++)
    {
        scanf(" %d", &a[i]);
    }
    root = insertLevelOrder(a, 1, n);
    displayLevelOrder(root);
}