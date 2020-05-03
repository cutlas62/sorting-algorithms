#include "../utils.h"
#include <stdbool.h>

statistics_t bubble_sort(int *arr, int n)
{
    statistics_t ret = {0};

	bool sorted = true;
    uint64_t start_time = microsSinceEpoch();
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n - i - 1; j++){
    		if (*(arr + j) > *(arr + j + 1)){
    			sorted = false;
    			// Swap them!
    			int tmp = *(arr + j);
    			*(arr + j) = *(arr + j + 1);
    			*(arr + j + 1) = tmp;
    		}
    	}
    	if(sorted){
    		break;
    	}
    }
    ret.time = microsSinceEpoch() - start_time;
    return ret;
}
