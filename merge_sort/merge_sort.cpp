#include "../utils.h"


void _merge_sort(int *arr, int l, int r, statistics_t * ret);
void _merge(int *arr, int l, int m, int r, statistics_t * ret);

statistics_t merge_sort(int *arr, int n)
{
	printf("Sorting array with merge sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();
    _merge_sort(arr, 0, n - 1, &ret);
    ret.time = microsSinceEpoch() - start_t;
    return ret;
}

void _merge_sort( int *arr, int l, int r, statistics_t * ret)
{
    if (r > l)
    {
        int m = (l + r) / 2;

        // Divide and conquer!
        _merge_sort(arr, l, m, ret);
        _merge_sort(arr, m + 1, r, ret);
        _merge(arr, l, m, r, ret);
    }

}

void _merge(int *arr, int l, int m, int r, statistics_t * ret)
{
	// Create temporary arrays
    int left_arr [m + 1 - l] = {0};
    int right_arr [r - m] = {0};

    // Fill them
    for (int i = 0; i < m + 1 - l; i++)
    {
        left_arr[i] = *(arr + l + i);
        ret->array_accesses++;
    }
    for (int i = 0; i < r - m; i++)
    {
        right_arr[i] = *(arr + m + 1 + i);
        ret->array_accesses++;
    }

    // Merge the two arrays sorted from low to high
    int i = 0;
    int j = 0;
    int k = l;
    while((i < m + 1 - l) && (j < r - m))
    {
        ret->comparisons++;
        if(left_arr[i] < right_arr[j])
        {
            *(arr + k) = left_arr[i];
            i++;
            ret->array_accesses++;
        }
        else
        {
            *(arr + k) = right_arr[j];
            j++;
            ret->array_accesses++;
        }
        k++;
    }

    // There is usually one number hanging, place it into the merged array as well
    while(i < m + 1 - l)
    {
        *(arr + k) = left_arr[i];
        i++;
        k++;
        ret->array_accesses++;
    }
    while(j < r - m)
    {
        *(arr + k) = right_arr[j];
        j++;
        k++;
        ret->array_accesses++;
    }

}