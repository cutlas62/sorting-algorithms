#include "../utils.h"


statistics_t shell_sort(int *arr, int n)
{
    printf("Sorting array with shell sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();

    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        // Like insertion sort but within sublists of element separated 'gap' elements from each other, instead of always 1
        for(int i = gap; i < n; i++)
        {
            for(int j = i; j >= gap; j -= gap)
            {
                ret.comparisons++;
                ret.array_accesses += 2;
                if (*(arr + j) < * (arr + j - gap))
                {
                    // Swap them
                    swap(arr + j, arr + j - gap);
                    ret.array_accesses += 4;
                }
                else
                {
                    break;
                }
            }
        }

    }

    ret.time = microsSinceEpoch() - start_t;

    return ret;
}
