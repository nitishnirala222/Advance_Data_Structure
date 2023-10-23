#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (i<=j) {

        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        swap(&arr[i],&arr[j]);
    }
}

int partition_random(int arr[], int low, int high)
{
    int random = low + rand() % (high - low);

    swap(&arr[low],&arr[random]);

    return partition(arr, low, high);
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition_random(arr, low, high);

        QuickSort(arr, low, pi);
        QuickSort(arr, pi + 1, high);
    }
}

void DisplayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting: ");
    DisplayArray(arr,n);
    QuickSort(arr, 0, n - 1);
    printf("After Sorting array: ");
    DisplayArray(arr, n);
}
