#include "../utils.h"
#include <cmath>
#include <bits/stdc++.h> 

#define THRESHOLD 10000000


/* Function prototypes */

// Heap functions
void _make_heap(int *arr, int _first, int _last);
void _adjust_heap(int *arr, int _first, int _hole, int _len, int _val);
void _push_heap(int *arr, int _first, int _hole, int _top, int _val);
void _pop_heap(int *arr, int _first, int _last, int _result);
void _sort_heap (int *arr, int _first, int _last);
void _select_heap(int *arr, int _first, int _middle, int _last);

// Sorts
void _sort(int *arr, int _first, int _last);
void _partial_sort(int *arr, int _first, int _middle, int _last);
void _insertion_sort(int *arr, int _first, int _last);
void _final_insertion_sort(int *arr, int _first, int _last);
void _unguarded_insertion_sort(int *arr, int _first, int _last);
void _introsort_loop(int *arr, int _first, int _last, int _depth_limit);


// Utils
int _unguarded_partition_pivot(int *arr, int _first, int _last);
int _unguarded_partition(int *arr, int _first, int _last, int _pivot);
void _unguarded_linear_insert(int *arr, int _last);
void _move_median_to_first(int *arr, int _result, int _a, int _b, int _c);
void _move_backwards(int *arr, int _first, int _last, int _dlast);
double _log2 (double n);








// Heap functions
void _make_heap(int *arr, int _first, int _last)
{
    int len = _last - _first;;
    if (len < 2)
    {
        return;
    }

    int parent = (len - 2) / 2;
    int val = 0;
    while (1)
    {
        val = *(arr + _first + parent);
        _adjust_heap(arr, _first, parent, len, val);
        if (parent == 0)
        {
            return;
        }
        parent--;
    }
}

void _adjust_heap(int *arr, int _first, int _hole, int _len, int _val)
{
    int top = _hole;
    int child = _hole;

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
    int tmp = *(arr + _result);
    *(arr + _result) = *(arr + _first);
    _adjust_heap(arr, _first, 0, _last - _first, tmp);
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


void _sort_heap (int *arr, int _first, int _last)
{
    while (_last - _first > 1)
    {
        --_last;
        _pop_heap(arr, _first, _last, _last);
    }
}





void _select_heap(int *arr, int _first, int _middle, int _last)
{
    int i;
    _make_heap(arr, _first, _middle);
    for (i = _middle; i < _last; i++)
    {
        if ((*arr + i) < * (arr + _first))
        {
            _pop_heap(arr, _first, _middle, i);
        }
    }
}



// Sorts
void _sort(int *arr, int _first, int _last)
{
    if (_first != _last)
    {
        _introsort_loop(arr, _first, _last, _log2((double)(_last - _first)) * 2);
        _final_insertion_sort(arr, _first, _last);
    }
}


void _partial_sort(int *arr, int _first, int _middle, int _last)
{
    _select_heap(arr, _first, _middle, _last);
    _sort_heap(arr, _first, _middle);
}


void _insertion_sort(int *arr, int _first, int _last)
{

    if (_first == _last)
    {
        return;
    }

    int val = 0;
    for (int i = _first + 1; i != _last; i++)
    {
        if (*(arr + i) < * (arr + _first))
        {
            val = *(arr + i);
            _move_backwards(arr, _first, i, i + 1);
            *(arr + _first) = val;
        }
        else
        {
            _unguarded_linear_insert(arr, i);
        }
    }
}


void _final_insertion_sort(int *arr, int _first, int _last)
{
    if (_last - _first > THRESHOLD)
    {
        _insertion_sort(arr, _first, _last + THRESHOLD);
        _unguarded_insertion_sort(arr, _first + THRESHOLD, _last);
    }
    else
    {
        _insertion_sort(arr, _first, _last);
    }
}


void _unguarded_insertion_sort(int *arr, int _first, int _last)
{
    for (int i = _first; i != _last; i++)
    {
        _unguarded_linear_insert(arr, i);
    }
}




// Utils
int _unguarded_partition_pivot(int *arr, int _first, int _last)
{
    int mid = _first + (_last - _first) / 2;
    _move_median_to_first(arr, _first, _first + 1, mid, _last - 1);
    return _unguarded_partition(arr, _first + 1, _last, _first);
}


int _unguarded_partition(int *arr, int _first, int _last, int _pivot)
{
    while(1)
    {
        while(*(arr + _first) < * (arr + _pivot))
        {
            _first++;
        }
        _last--;
        while(*(arr + _pivot) < * (arr + _last))
        {
            _last--;
        }
        if (!(_first < _last))
        {
            return _first;
        }
        swap(arr + _first, arr + _last);
        _first++;
    }
}


void _unguarded_linear_insert(int *arr, int _last)
{
    int val = *(arr + _last);
    int next = _last;
    --next;
    while (val < * (arr + next))
    {
        *(arr + _last) = *(arr + next);
        _last = next;
        --next;
    }
    *(arr + _last) = val;
}


void _introsort_loop(int *arr, int _first, int _last, int _depth_limit)
{
    int pivot = 0;
    while (_last - _first > THRESHOLD)
    {
        if (_depth_limit == 0)
        {
            _partial_sort(arr, _first, _last, _last);
            return;
        }

        --_depth_limit;
        pivot = _unguarded_partition_pivot(arr, _first, _last);
        _introsort_loop(arr, pivot, _last, _depth_limit);
        _last = pivot;
    }
}


void _move_median_to_first(int *arr, int _result, int _a, int _b, int _c)
{
    if (*(arr + _a) < * (arr + _b))
    {
        if (*(arr + _b) < * (arr + _c))
        {
            swap(arr + _result, arr + _b);
        }
        else if (*(arr + _a) < * (arr + _c))
        {
            swap(arr + _result, arr + _c);
        }
        else
        {
            swap(arr + _result, arr + _a);
        }
    }
    else if (*(arr + _a) < * (arr + _c))
    {
        swap(arr + _result, arr + _a);
    }
    else if (*(arr + _b) < * (arr + _c))
    {
        swap(arr + _result, arr + _c);
    }
    else
    {
        swap(arr + _result, arr + _b);
    }
}


void _move_backwards(int *arr, int _first, int _last, int _dlast)
{
    while (_first != _last)
    {
        _dlast--;
        _last--;
        *(arr + _dlast) = *(arr + _last);
    }
}


double _log2 (double n)
{
    return log(n) / log(2.0);
}




statistics_t gcc_std_sort(int *arr, int n)
{
    // https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_algo.h#L1950

    printf("Sorting array with gcc_std sort...\n\n");
    statistics_t ret = {0};
    uint64_t start_t = microsSinceEpoch();

    std::sort(arr, arr + n);
    //_sort(arr, 0, n);


    ret.time = microsSinceEpoch() - start_t;
    return ret;
}