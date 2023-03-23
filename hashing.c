#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 10
int hash_table[HASH_SIZE];
int H(int k)
{
    return k % HASH_SIZE;
}
void insert_table(int item)
{
    int i, index, hval;
    hval = H(item);
    for (i = 0; i < HASH_SIZE; i++)
    {
        index = (hval + i) % HASH_SIZE;
        if (hash_table[index] == 0)
        {
            hash_table[index] = item;
            break;
        }
    }
    if (i == HASH_SIZE)
    {
        printf("\nHASH FULL\n");
    }
}
void display()
{
    printf("BUCKET\tITEM\n");
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (hash_table[i] != 0)
        {
            printf("%d\t%d\n", i, hash_table[i]);
        }
    }
}
void main()
{
    printf("size: ");
    int n, item;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf(" %d", &item);
        insert_table(item);
    }
    display();
}