#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int* A, int* B)
{
    // Dereference the variable to get the value.
    int tempC = *A;

    // Copy the pointer.
    *A = *B;
    
    // Transfer the temp to B.
    // Note: Dereference B to transfer value.
    *B = tempC;

}
void bubbleSort(int arr [], int size)
{
    
    for(int i = 0; i < (size-1); i++)
    {
        // no need to check the last index because its already sorted.
        // Therefore the pass through for the last interation decrements.
        for(int j = 0; j < size - i -1 ; j ++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
            
        }
    }
}

void printArray(int arr [], int size)
{
    for(int i = 0; i < size; i ++)
    {
        printf("%d ", arr[i]);
    } 
    cout << endl;
}
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/ sizeof(arr[0]);
    printf("Unsorted Array: ");
    printArray(arr,size);

    bubbleSort(arr,size);
    printf("Sorted Array: ");
    printArray(arr,size);
    
}