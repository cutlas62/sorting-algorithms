#include "../utils.h"
#include <climits>

statistics_t selection_sort(int *arr, int n)
{
    printf("Sorting array with selection sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();

    for(int i = 0; i < n - 1; i++)
    {
        // Find the minimum value in the subarray [i, n-1]
        int min_value = INT_MAX;
        int min_index = 0;
        for(int j = i; j < n; j++)
        {
            ret.comparisons++;
            ret.array_accesses++;
            if(*(arr + j) < min_value)
            {
                min_value = *(arr + j);
                min_index = j;
                ret.array_accesses++;
            }
        }

        // Move the minimum value to the curent 'i' position
        swap(arr + i, arr + min_index);
        ret.array_accesses += 4;

    }

    ret.time = microsSinceEpoch() - start_t;
    return ret;
}

