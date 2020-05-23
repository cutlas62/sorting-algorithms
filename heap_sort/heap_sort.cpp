#include "../utils.h"


/*
Root is at index 0 in array.
Left child of i-th node is at (2*i + 1)th index.
Right child of i-th node is at (2*i + 2)th index.
Parent of i-th node is at (i-1)/2 index.
*/



void min_heapify(int *arr, int n, int i)
{
    // If right child is bigger, swap them and min_heapify subtrees
    if(2 * i + 2 < n)
    {
        if(*(arr + 2 * i + 2) > *(arr + i))
        {
            swap(arr + 2 * i + 2, arr + i);
            min_heapify(arr, n, 2 * i + 2);
        }
    }

    // If left child is bigger, swap them and min_heapify subtrees
    if(2 * i + 1 < n)
    {
        if(*(arr + 2 * i + 1) > *(arr + i))
        {
            swap(arr + 2 * i + 1, arr + i);
            min_heapify(arr, n, 2 * i + 1);
        }
    }


}


statistics_t heap_sort(int *arr, int n)
{
    printf("Sorting array with heap sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();


    // Move the maximum element to the root
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(arr, n, i);
    }

    // Move each element to the root and min_heapify again
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr + i, arr);
        min_heapify(arr, i, 0);
    }

    ret.time = microsSinceEpoch() - start_t;
    return ret;
}