#include "../utils.h"
#include <cmath>

#define THRESHOLD 16


/* Function prototypes */

void _make_heap(int *arr, int _first, int _last);
void _adjust_heap(int *arr, int _first, int _hole, int _len, int _val);
void _push_heap(int *arr, int _first, int _hole, int _top, int _val);
void _pop_heap(int *arr, int _first, int _last, int _result);
void _sort_heap (int *arr, int _first, int _last);
void _select_heap(int *arr, int _first, int _middle, int _last);
void _sort(int *arr, int _first, int _last);
void _insertion_sort(int *arr, int _first, int _last);
void _partial_sort(int *arr, int _first, int _middle, int _last);
void _introsort_loop(int *arr, int _first, int _last, int _depth_limit);
int _unguarded_partition_pivot(int *arr, int _first, int _last);
int _unguarded_partition(int *arr, int _first, int _last, int _pivot);
void _unguarded_linear_insert(int *arr, int _last);
void _move_median_to_first(int *arr, int _result, int _a, int _b, int _c);
void _move_backwards(int *arr, int _first, int _last, int _dlast);
double _log2 (double n);

static statistics_t *st;


void _make_heap(int *arr, int _first, int _last)
{
    _make_heap_n++;
    int len = _last - _first;;
    if (len < 2)
    {
        return;
    }

    int parent = (len - 2) / 2;
    int val = 0;
    while (1)
    {
        st->array_accesses++;
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
    _adjust_heap_n++;
    int top = _hole;
    int child = _hole;

    while (child < (_len - 1) / 2)
    {
        child = 2 * (child + 1);
        st->array_accesses += 2;
        st->comparisons++;
        if (*(arr + _first + child) < * (arr + _first + (child - 1)))
        {
            child--;
        }

        st->array_accesses += 2;
        *(arr + _first + _hole) = *(arr + _first + child);
        _hole = child;
    }

    if ((_len & 1) == 0 && child == (_len - 2) / 2)
    {
        child = 2 * (child + 1);
        st->array_accesses += 2;
        *(arr + _first + _hole) = *(arr + _first + (child - 1));
        _hole = child - 1;
    }

    _push_heap(arr, _first, _hole, top, _val);
}


void _pop_heap(int *arr, int _first, int _last, int _result)
{
    _pop_heap_n++;
    st->array_accesses += 3;
    int tmp = *(arr + _result);
    *(arr + _result) = *(arr + _first);
    _adjust_heap(arr, _first, 0, _last - _first, tmp);
}


void _push_heap(int *arr, int _first, int _hole, int _top, int _val)
{
    _push_heap_n++;
    int parent = (_hole - 1) / 2;
    st->comparisons += 2;
    while (_hole > _top && (*(arr + _first + parent) < _val))
    {
        st->array_accesses += 3;
        *(arr + _first + _hole) = *(arr + _first + parent);
        _hole = parent;
        parent = (_hole - 1) / 2;
    }
    *(arr + _first + _hole) = _val;
    st->array_accesses++;
}


void _sort_heap (int *arr, int _first, int _last)
{
    _sort_heap_n++;
    while (_last - _first > 1)
    {
        --_last;
        _pop_heap(arr, _first, _last, _last);
    }
}


void _select_heap(int *arr, int _first, int _middle, int _last)
{
    _select_heap_n++;
    _make_heap(arr, _first, _middle);
    for (int i = _middle; i < _last; i++)
    {
        st->comparisons += 2;
        st->array_accesses += 2;
        if ((*arr + i) < * (arr + _first))
        {
            _pop_heap(arr, _first, _middle, i);
        }
    }
}


void _sort(int *arr, int _first, int _last)
{
    _sort_n++;
    if (_first != _last)
    {
        // Heap or quick sort if the number of elements is above THRESHOLD
        _introsort_loop(arr, _first, _last, 2 * _log2((_last - _first)));
        // Else, normal insertion sort
        _insertion_sort(arr, _first, _last);
    }
}


void _partial_sort(int *arr, int _first, int _middle, int _last)
{
    _partial_sort_n++;
    _select_heap(arr, _first, _middle, _last);
    _sort_heap(arr, _first, _middle);
}


void _insertion_sort(int *arr, int _first, int _last)
{
    _insertion_sort_n++;
    if (_first == _last)
    {
        return;
    }

    int val = 0;
    for (int i = _first + 1; i != _last; i++)
    {
        st->array_accesses += 2;
        st->comparisons++;
        if (*(arr + i) < * (arr + _first))
        {
            val = *(arr + i);
            _move_backwards(arr, _first, i, i + 1);
            *(arr + _first) = val;
            st->array_accesses += 2;
        }
        else
        {
            _unguarded_linear_insert(arr, i);
        }
    }
}


int _unguarded_partition_pivot(int *arr, int _first, int _last)
{
    _unguarded_partition_pivot_n++;
    int mid = _first + (_last - _first) / 2;
    _move_median_to_first(arr, _first, _first + 1, mid, _last - 1);
    return _unguarded_partition(arr, _first + 1, _last, _first);
}


int _unguarded_partition(int *arr, int _first, int _last, int _pivot)
{
    _unguarded_partition_n++;
    while(1)
    {
        st->array_accesses += 2;
        st->comparisons++;
        while(*(arr + _first) < * (arr + _pivot))
        {
            _first++;
            st->array_accesses += 2;
            st->comparisons++;
        }
        _last--;
        st->array_accesses += 2;
        st->comparisons++;
        while(*(arr + _pivot) < * (arr + _last))
        {
            _last--;
            st->array_accesses += 2;
            st->comparisons++;
        }
        st->comparisons++;
        if (!(_first < _last))
        {
            return _first;
        }
        st->array_accesses += 3;
        swap(arr + _first, arr + _last);
        _first++;
    }
}


void _unguarded_linear_insert(int *arr, int _last)
{
    _unguarded_linear_insert_n++;
    st->array_accesses++;
    int val = *(arr + _last);
    int next = _last - 1;
    st->array_accesses++;
    st->comparisons++;
    while (val < * (arr + next))
    {
        *(arr + _last) = *(arr + next);
        _last = next;
        --next;
        st->array_accesses += 3;
        st->comparisons++;
    }
    st->array_accesses++;
    *(arr + _last) = val;
}


void _introsort_loop(int *arr, int _first, int _last, int _depth_limit)
{
    _introsort_loop_n++;
    int pivot = 0;

    while (_last - _first > THRESHOLD)
    {
        if (_depth_limit == 0)
        {
            // If the depth is 0, use heap sort
            _partial_sort(arr, _first, _last, _last);
            return;
        }
        // Find pivot and perform quick sort
        --_depth_limit;
        pivot = _unguarded_partition_pivot(arr, _first, _last);
        _introsort_loop(arr, pivot, _last, _depth_limit);
        _last = pivot;
    }
}


void _move_median_to_first(int *arr, int _result, int _a, int _b, int _c)
{
    _move_median_to_first_n++;
    if (*(arr + _a) < * (arr + _b))
    {
        st->comparisons++;
        if (*(arr + _b) < * (arr + _c))
        {
            st->comparisons++;
            st->array_accesses += 5;
            swap(arr + _result, arr + _b);
        }
        else if (*(arr + _a) < * (arr + _c))
        {
            st->comparisons += 2;
            st->array_accesses += 6;
            swap(arr + _result, arr + _c);
        }
        else
        {
            st->comparisons += 2;
            st->array_accesses += 6;
            swap(arr + _result, arr + _a);
        }
    }
    else if (*(arr + _a) < * (arr + _c))
    {
        st->comparisons += 2;
        st->array_accesses += 5;
        swap(arr + _result, arr + _a);
    }
    else if (*(arr + _b) < * (arr + _c))
    {
        st->comparisons += 3;
        st->array_accesses += 6;
        swap(arr + _result, arr + _c);
    }
    else
    {
        st->comparisons += 3;
        st->array_accesses += 6;
        swap(arr + _result, arr + _b);
    }
}


void _move_backwards(int *arr, int _first, int _last, int _dlast)
{
    _move_backwards_n++;
    while (_first != _last)
    {
        _dlast--;
        _last--;
        st->array_accesses += 2;
        *(arr + _dlast) = *(arr + _last);
    }
}


double _log2 (double n)
{
    _log2_n++;
    return log(n) / log(2.0);
}




statistics_t gcc_std_sort(int *arr, int n)
{
    // https://github.com/gcc-mirror/gcc/blob/d9375e490072d1aae73a93949aa158fcd2a27018/libstdc%2B%2B-v3/include/bits/stl_algo.h#L1950

    printf("Sorting array with gcc_std sort...\n\n");
    st = new statistics_t;
    uint64_t start_t = microsSinceEpoch();

    _sort(arr, 0, n);

    statistics_t ret = *st;
    ret.time = microsSinceEpoch() - start_t;
    return ret;
}