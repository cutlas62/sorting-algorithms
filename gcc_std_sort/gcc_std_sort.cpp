#include "../utils.h"
#include <cmath>

/* Function prototypes */

// Heap functions
void _make_heap(int _first, int _last);								// TODO
void _pop_heap(int _first, int _middle, int _result);				// TODO
void _push_heap(int _first, int _hole, int _top, int _val);			// TODO
void _sort_heap (int _first, int _last);							// TODO
void _adjust_heap(int _first, int _hole, int _len, int _val);		// TODO
void _heap_select(int _first, int _middle, int _last);				// TODO

// Sorts
void _sort(int _first, int _last);									// TODO
void _partial_sort(int _first, int _middle, int _last);				// TODO
void _insertion_sort(int _first, int _last);						// TODO
void _final_insertion_sort(int _first, int _last);					// TODO
void _unguarded_insertion_sort(int _first, int _last);				// TODO
void _introsort_loop(int _first, int _last, int _depth_limit);		// TODO


// Utils
int _unguarded_partition_pivot(int _first, int _last);				// TODO
int _unguarded_partition(int _first, int _last, int _pivot);		// TODO
void _unguarded_linear_insert(int _last);							// TODO
void _move_median_to_first(int _result, int _a, int _b, int _c);	// TODO
void _move_backwards(int _first, int _last, int _dlast);			// TODO
double _lg (double n);








// Heap functions
void _make_heap(int _first, int _last)
{

}


void _pop_heap(int _first, int _middle, int _result)
{

}


void _push_heap(int _first, int _hole, int _top, int _val)
{

}


void _sort_heap (int _first, int _last)
{

}


void _adjust_heap(int _first, int _hole, int _len, int _val)
{

}


void _heap_select(int _first, int _middle, int _last)
{

}



// Sorts
void _sort(int _first, int _last)
{

}


void _partial_sort(int _first, int _middle, int _last)
{

}


void _insertion_sort(int _first, int _last)
{

}


void _final_insertion_sort(int _first, int _last)
{

}


void _unguarded_insertion_sort(int _first, int _last)
{

}




// Utils
int _unguarded_partition_pivot(int _first, int _last)
{
	return 0;
}


int _unguarded_partition(int _first, int _last, int _pivot)
{
	return 0;
}


void _unguarded_linear_insert(int _last)
{

}


void _introsort_loop(int _first, int _last, int _depth_limit)
{

}


void _move_median_to_first(int _result, int _a, int _b, int _c)
{

}


void _move_backwards(int _first, int _last, int _dlast)
{

}


double _lg (double n)
{
    return log(n) / log(2.0);
}




statistics_t gcc_std_sort(int *arr, int n)
{
    // https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_algo.h#L1950

    printf("Sorting array with gcc_std sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();







    ret.time = microsSinceEpoch() - start_t;
    return ret;
}