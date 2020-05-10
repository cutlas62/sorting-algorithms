#include "../utils.h"

statistics_t radix_sort(int *arr, int n)
{
    printf("Sorting array with radix sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();



    for(int p = 1; p <= 1000000000; p *= 10)
    {
    	// Create the count array
        int count [10] = {0};

        // Create and populate the temporary input array
        int in[n];
        for(int i = 0; i < n; i++)
        {
            in[i] = *(arr + i);
        }
        ret.array_accesses += n;

        // From here, it's a counting sorting algorithm depending on the digit at position 'p'
        for(int i = 0; i < n; i++)
        {
            int digit = ((in[i] / p) % 10);
            count[digit]++;
        }
        ret.array_accesses += 2*n;

        for(int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        ret.array_accesses += 2*n;

        for(int i = n - 1; i >= 0; i--)
        {
            int digit = (in[i] / p) % 10;
            *(arr + count[digit] - 1) = in[i];
            count[digit]--;
        }
        // No comparisons at all... Amazing
    }


    ret.time = microsSinceEpoch() - start_t;
    return ret;
}