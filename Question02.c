#include<stdio.h>
int main()
{
    int size, i;
    printf("Enter the size of the Hash Table: ");
    scanf("%d", &size);
    int Htable[size],keys[size];
    printf("enter %d keys respectively: ",size);
    for(int i=0;i<size; i++)
        scanf("%d",&keys[i]);

    for(i = 0; i < size; i ++)
    {
        Htable[i] = (keys[i] % size);
    }
    printf("\nThe indexes of the values in the Hash Table: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", Htable[i]);
    }
}
