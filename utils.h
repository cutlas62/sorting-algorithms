#ifndef MAIN_INCLUDE_H
#define MAIN_INCLUDE_H
#include <cstdint>
#include <sys/time.h>
#include <cstddef>
#include <cstdio>

struct statistics_t {
    uint64_t time;
    uint64_t comparisons;
    uint64_t array_accesses;
};

void print_array(int *arr, int n);
void swap (int *f, int *s);
uint64_t microsSinceEpoch(void);

#endif