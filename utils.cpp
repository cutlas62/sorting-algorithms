#include "utils.h"


void print_array(int *arr, int n)
{
    int n_columns = 5;
    int n_rows = n / n_columns + 1;
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_columns; j++)
        {
            if((i * n_columns + j) < n)
            {
                printf("%d", *(arr + i * n_columns + j));
                printf("\t");
            }
        }
        printf("\n");
    }
}



uint64_t microsSinceEpoch(void)
{
    struct timeval tv;
    uint64_t micros = 0;
    gettimeofday(&tv, NULL);
    micros =  ((uint64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
    return micros;
}