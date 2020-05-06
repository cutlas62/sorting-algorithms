#include "../utils.h"

statistics_t cocktail_shaker_sort(int *arr, int n)
{
	printf("Sorting array with cocktail shaker sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_time = microsSinceEpoch();

    for(int r = 0; r < n / 2; r++)
    {
        // From left to right
        for(int i = r; i < n - 1 - r; i++)
        {
            ret.comparisons++;
            ret.array_accesses += 2;
            if(*(arr + i) > *(arr + i + 1))
            {
                // Swap them
                int tmp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = tmp;
                ret.array_accesses += 4;
            }
        }

        // From right to left
        for(int j = n - 2 - r; j > r; j--)
        {
            ret.comparisons++;
            ret.array_accesses += 2;
            if(*(arr + j) < * (arr + j - 1))
            {
                // Swap them
                int tmp = *(arr + j);
                *(arr + j) = *(arr + j - 1);
                *(arr + j - 1) = tmp;
                ret.array_accesses += 4;
            }
        }
    }

    ret.time = microsSinceEpoch() - start_time;
    return ret;
}