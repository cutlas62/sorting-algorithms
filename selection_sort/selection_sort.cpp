#include "../utils.h"
#include <climits>

statistics_t selection_sort(int *arr, int n)
{
    printf("Sorting array with selection sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();

    for(int i = 0; i < n - 1; i++)
    {
        // Find the minimum value in the subarray [j, n-1]
        int min_value = INT_MAX;
        int min_index = 0;
        for(int j = i + 1; j < n; j++)
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

        // If the minimum value in the subarray (min_index) is lower than the current selected (i), swap them
        ret.comparisons++;
        ret.array_accesses = ret.array_accesses + 2;
        if(*(arr + min_index) < * (arr + i))
        {
            // Swap them!
            int tmp = *(arr + i);
            *(arr + i) = *(arr + min_index);
            *(arr + min_index) = tmp;
            ret.array_accesses = ret.array_accesses + 4;
        }

    }

    ret.time = microsSinceEpoch() - start_t;
    return ret;
}

