#include "../utils.h"

statistics_t gnome_sort(int *arr, int n)
{
    printf("Sorting array with gnome sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_time = microsSinceEpoch();


    for(int i = 1; i < n;)
    {
    	// If they are not in the correct order, swap them and go back
    	ret.comparisons++;
    	ret.array_accesses += 2;
        if(*(arr + i) < * (arr + i - 1))
        {
        	ret.array_accesses += 4;
            swap(arr + i, arr + i - 1);
            if(i > 1)
            {	
                i--;
            }
        }
        // If they are in the correct order, move to the next ones
        else
        {
        	i++;
            continue;
        }

    }


    ret.time = microsSinceEpoch() - start_time;
    return ret;
}