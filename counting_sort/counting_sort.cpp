#include "../utils.h"

statistics_t counting_sort(int *arr, int n)
{
    /* 	For counting sort, we ususally get the maximum number,
    	so this doesn't count towards the time complexity
    */

	int max_val = 0;
    for(int i = 0; i < n; i++){
    	if(*(arr + i) > max_val){
    		max_val = *(arr + i);
    	}
    }

    unsigned int counting_array [max_val] = {0};


    /* Start the sorting algorithm */
    printf("Sorting array with counting sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();


    

    ret.time = microsSinceEpoch() - start_t;
    return ret;
}