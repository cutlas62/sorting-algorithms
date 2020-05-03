#include "utils.h"

uint64_t microsSinceEpoch(void)
{
    struct timeval tv;
    uint64_t micros = 0;
    gettimeofday(&tv, NULL);
    micros =  ((uint64_t)tv.tv_sec) * 1000000 + tv.tv_usec;
    return micros;
}