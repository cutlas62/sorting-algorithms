#include "../utils.h"

statistics_t shell_sort(int *arr, int n)
{
    printf("Sorting array with shell sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();

    // Compare starting with gap = n/2 and follow Knuth's formula (gap = gap * 3 + 1 < n)
    int max_gap = 0;
    while(max_gap < n / 3)
    {
        max_gap = max_gap * 3 + 1;
    }

    for(int gap = 8; gap > 0; gap = gap / 2)
    {
        printf("gap = %d\n", gap);
        print_array(arr, n);
        for(int i = 0; i < gap; i++)
        {

            if(i + gap < n)
            {
                if(*(arr + i) > *(arr + i + gap))
                {
                    int tmp = *(arr + i + gap);
                    *(arr + i + gap) = *(arr + i);
                    *(arr + i) = tmp;
                }
            }
        }



    }




    ret.time = microsSinceEpoch() - start_t;
    return ret;
}