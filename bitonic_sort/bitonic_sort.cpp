#include "../utils.h"
#include <climits>

statistics_t bitonic_sort(int *arr, int n)
{

    // https://en.wikipedia.org/wiki/Bitonic_sorter#/media/File:BitonicSort1.svg

    printf("Sorting array with bitonic sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_time = microsSinceEpoch();

    // Let's make the array have 2^x elements
    int max_n = 1;
    do
    {
        max_n *= 2;
    }
    while(max_n * 2 <= n);

    if(max_n != n)
    {
        printf("Warning:\tBitonic sort only works with arrays of 2^x elements.\n\t\t%d is not a power of 2, so let's sort only the first %d elements.\n\n", n, max_n);
        for(int i = max_n; i < n; i++)
        {
            // Let's not count these towards the array_accesses number
            *(arr + i) = INT_MAX;
        }
    }

    // Divide the array into chunks of 'block' size
    for (int block = 2; block <= max_n; block *= 2)
    {
        // Determine the gap size, starting at block / 2
        for (int gap = block / 2; gap > 0; gap /= 2)
        {
            for (int i = 0; i < max_n; ++i)
            {

                int j = i ^ gap;
                if (i < j)
                {
                    // Ascending sequence
                    if ( (i & block) != 0)
                    {
                        ret.comparisons++;
                        ret.array_accesses += 2;
                        if (*(arr + i) < * (arr + j))
                        {
                            ret.array_accesses += 4;
                            swap(arr + i, arr + j);
                        }
                    }
                    // Descending sequence
                    else
                    {
                        ret.comparisons++;
                        ret.array_accesses += 2;
                        if (*(arr + i) > *(arr + j))
                        {
                            ret.array_accesses += 4;
                            swap(arr + i, arr + j);
                        }
                    }
                }
            }
        }
    }


    ret.time = microsSinceEpoch() - start_time;
    return ret;
}
