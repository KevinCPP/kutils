#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#define _POSIX_C_SOURCE 200809L
#include <time.h>

#include "ku_sorting.h"
#include "ku_comparators.h"

#define SMALL_SIZE 50
#define MEDIUM_SIZE 500
#define LARGE_SIZE 5000
#define VLARGE_SIZE 50000
#define TIME_FUNCTION(call, message) do { \
    struct timespec start, end; \
    clock_gettime(CLOCK_MONOTONIC, &start); \
    call; \
    clock_gettime(CLOCK_MONOTONIC, &end); \
    long long duration = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_nsec - start.tv_nsec) / 1000; \
    printf("%s%lld microseconds\n", message, duration); \
} while (0)

void print_ints(void* a, size_t len) {
    for(size_t i = 0; i < len; i++) {
        printf("%d ", *((int*)a + len));
    } printf("\n");
}

int main() {
    int* small = (int*)malloc(SMALL_SIZE * sizeof(int));
    int* medium = (int*)malloc(MEDIUM_SIZE * sizeof(int));
    int* large = (int*)malloc(LARGE_SIZE * sizeof(int));
    int* vlarge = (int*)malloc(VLARGE_SIZE * sizeof(int));
   
    if(small == NULL || medium == NULL || large == NULL || vlarge == NULL)
        return -1;

    srand(time(NULL));
    size_t i;
    for(i = 0; i < VLARGE_SIZE; i++) {
        if(i <  SMALL_SIZE)
            small[i] = rand() % SMALL_SIZE;
        if(i < MEDIUM_SIZE)
            medium[i] = rand() % MEDIUM_SIZE;
        if(i < LARGE_SIZE)
            large[i] = rand() % LARGE_SIZE;

        vlarge[i] = rand() % VLARGE_SIZE;
    }

    TIME_FUNCTION(ku_mergesort(vlarge, VLARGE_SIZE, sizeof(int), ku_int_cmp), "merge sort: ");

    free(small);
    free(medium);
    free(large);
    free(vlarge);

    return 0;
}
