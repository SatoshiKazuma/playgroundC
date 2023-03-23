#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char id[10];
    char name[20];
    char branch[10];
    char spec[10];
    struct node *left, *right;
} Node;
Node *insert_front(Node *first)
{
    printf("\nfront insert\nID\tNAME\tBRANCH\tSPEC\n");
    Node *temp = (Node *)malloc(sizeof(Node));
    scanf(" %s%s%s%s", temp->id, temp->name, temp->branch, temp->spec);
    temp->left = temp->right = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->right = first;
        first->left = temp;
        first = temp;
    }
    return first;
}
Node *delete_front(Node *first)
{
    printf("\nDelete front\n");
    if (first == NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        Node *temp;
        temp = first;
        first = ((first->right == NULL) ? NULL : first->right);
        free(temp);
    }
    printf("\nDelete Successful\n");
    return first;
}
void display(Node *first)
{
    if (first == NULL)
    {
        printf("\nEmpty list\n");
    }
    else
    {
        Node *cur = first;
        printf("\nID\tNAME\tBRANCH\tSPEC\n");
        while (cur != NULL)
        {
            printf("\n%s\t%s\t%s\t%s\n", cur->id, cur->name, cur->branch, cur->spec);
            cur = cur->right;
        }
    }
}
Node *insert_rear(Node *first)
{
    printf("\nfront insert\nID\tNAME\tBRANCH\tSPEC\n");
    Node *temp = (Node *)malloc(sizeof(Node)), *cur;
    scanf(" %s%s%s%s", temp->id, temp->name, temp->branch, temp->spec);
    temp->left = temp->right = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        cur = first;
        while (cur->right != NULL)
        {
            cur = temp->right;
        }
        cur->right = temp;
        temp->left = cur;
    }
    return first;
}

void stack(int n)
{
    Node *first = NULL;
    int choice;
    while (1)
    {
        printf("\nSTACK\n1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT\nCHOICE: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                first = insert_front(first);
            }
            break;
        case 2:
            first = delete_front(first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}
void queue(int n)
{
    Node *first = NULL;
    int choice;
    while (1)
    {
        printf("\nQUEUE\n1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT\nCHOICE: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                first = insert_rear(first);
            }
            break;
        case 2:
            first = delete_front(first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}

void main()
{
    int n, choice;
    printf("\nsize of list: ");
    scanf(" %d", &n);
    while (1)
    {
        printf("1.STACK\t2.QUEUE\t3.EXIT\nCHOICE: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            stack(n);
            break;
        case 2:
            queue(n);
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    }
}