
#include <stdbool.h>

void bubble_sort(int *arr, int n)
{
	bool sorted = true;
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
}
