#include <iostream>
#include <stdio.h>
using namespace std;

// #Notes:
/*
    1. Always pick first element as pivot
    2. Always pick last element as pivot (implemented below)
    3. Pick a random element as pivot
    4. Pick median as pivot

*/

void swap(int* a, int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// "partition" takes the last element as a pivot
// places the pivot element at its correct positio in sorted array
// places all smaller to the left of the pivot and all greater elements to right of pivot
int partition(int arr[], int low, int high)
{
    // pivot will be at the last element of the pivot.
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high-1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            // increment the 'i' counter
            i++;
            // swap the position 
            swap(&arr[i], &arr[j]);
        }
    }
    // place the pivot at the end of the sorted partition
    swap(&arr[i+1], &arr[high]);
    
    return (i+1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index
        // arr[p] is now at right place
        /*
            low     --> Starting index.
            high    --> Ending index.
        */
        int pi = partition(arr, low, high);

        //Separately sort elements before partition and after partition
        quickSort(arr,low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


//  function to prints an array
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr,n);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr,n);
    return 0;
}
