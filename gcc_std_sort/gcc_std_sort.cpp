#include "../utils.h"
#include <cmath>

/* Function prototypes */

// Heap functions
void _make_heap(int *arr, int _first, int _last);
void _adjust_heap(int *arr, int _first, int _hole, int _len, int _val);
void _push_heap(int *arr, int _first, int _hole, int _top, int _val);
void _pop_heap(int *arr, int _first, int _last, int _result);				// TODO
void _sort_heap (int _first, int _last);							// TODO
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
void _make_heap(int *arr, int _first, int _last)
{
    int len = 0;
    int parent = 0;
    int val = 0;

    len = _last - _first;
    if (len < 2)
        return;

    parent = (len - 2) / 2;
    while (1)
    {
        val = *(arr + _first + parent);
        _adjust_heap(arr, _first, parent, len, val);
        if (parent == 0)
            return;
        parent--;
    }
}

void _adjust_heap(int *arr, int _first, int _hole, int _len, int _val)
{
    int top = 0;
    int child = 0;

    top = _hole;
    child = _hole;
    while (child < (_len - 1) / 2)
    {
        child = 2 * (child + 1);
        if (*(arr + _first + child) < * (arr + _first + (child - 1)))
        {
            child--;
        }

        *(arr + _first + _hole) = *(arr + _first + child);
        _hole = child;
    }

    if ((_len & 1) == 0 && child == (_len - 2) / 2)
    {
        child = 2 * (child + 1);
        *(arr + _first + _hole) = *(arr + _first + (child - 1));
        _hole = child - 1;
    }

    _push_heap(arr, _first, _hole, top, _val);
}


void _pop_heap(int *arr, int _first, int _last, int _result)
{
    int val = *(arr + _result);
    *(arr + _result) = *(arr + _first);
    _adjust_heap(arr, _first, 0, _last - _first, val);
}


void _push_heap(int *arr, int _first, int _hole, int _top, int _val)
{
    int parent = (_hole - 1) / 2;
    while (_hole > _top && (*(arr + _first + parent) < _val))
    {
        *(arr + _first + _hole) = *(arr + _first + parent);
        _hole = parent;
        parent = (_hole - 1) / 2;
    }
    *(arr + _first + _hole) = _val;
}


void _sort_heap (int _first, int _last)
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


    printf("Making heap\n");
    _make_heap(arr, 0, n - 1);
    printf("Heap made\n");


    ret.time = microsSinceEpoch() - start_t;
    return ret;
}