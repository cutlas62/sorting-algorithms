#include "../utils.h"

#define MAX_VAL_ALLOWED	1000000

statistics_t counting_sort(int *arr, int n)
{
    /* 	For counting sort, we ususally get the maximum number,
    	so this doesn't count towards the time complexity
    */
    int max_val = 0;
    for(int i = 0; i < n; i++)
    {
        if(*(arr + i) > max_val)
        {
            max_val = *(arr + i);
        }
    }

    if(max_val > MAX_VAL_ALLOWED)
    {
        printf("\n%d is higher than %d so we have to decrease the array.\n", max_val, MAX_VAL_ALLOWED);
        max_val = 0;
        for(int i = 0; i < n; i++)
        {
            *(arr + i) = *(arr + i) % MAX_VAL_ALLOWED;
            if(*(arr + i) > max_val)
            {
                max_val = *(arr + i);
            }

        }
    }


    // Start the sorting algorithm
    printf("Sorting array with counting sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();

    int counting_array [max_val + 1] = {0};

    // Count how many times a value appears
    ret.array_accesses++;
    for(int i = 0; i < n; i++)
    {
        counting_array[*(arr + i)]++;
    }


    // And reconstruct the sorted array
    int index = 0;
    for(int i = 0; i < max_val + 1; i++)
    {
        for(int j = 0; j < counting_array[i]; j++)
        {
        	ret.array_accesses++;
            *(arr + index++) = i;
        }
    }

    ret.time = microsSinceEpoch() - start_t;
    return ret;
}