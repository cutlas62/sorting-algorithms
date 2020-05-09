#include "../utils.h"

int _partition(int *arr, int l, int r, statistics_t * ret)
{
	// Use first element (position l) as pivot
    int i = r;

    for (int j = r; j > l; j--)
    {
    	ret->comparisons++;
    	ret->array_accesses += 2;
        if (*(arr + j) > *(arr + l))
        {
        	ret->array_accesses += 2;
            swap(arr + i, arr + j);
            i--;
        }
    }
    ret->array_accesses += 2;
    swap(arr + i, arr + l);
    return i;
}



void _quick_sort(int *arr, int l, int r, statistics_t * ret)
{
    if(l < r)
    {
        int p = _partition(arr, l, r, ret);
        _quick_sort(arr, l, p - 1, ret);
        _quick_sort(arr, p + 1, r, ret);
    }
}





statistics_t quick_sort(int *arr, int n)
{
	printf("Sorting array with quick sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_time = microsSinceEpoch();

    _quick_sort(arr, 0, n - 1, &ret);

    ret.time = microsSinceEpoch() - start_time;
    return ret;
}