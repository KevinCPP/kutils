#ifndef SORTING_H
#define SORTING_H

#include <stddef.h>

// various sorting algorithms that can be specifically chosen by the user
int ku_insertionsort(void* array, size_t length, size_t size, int (*cmp)(const void* a, const void* b));
//void ku_countingsort(void* array, size_t length, size_t size, int (*cmp)(const void* a, const void* b));
int ku_mergesort(void* array, size_t length, size_t size, int (*cmp)(const void* a, const void* b));
int ku_quicksort(void* array, size_t length, size_t size, int (*cmp)(const void* a, const void* b));
//void ku_radixsort(void* array, size_t length, size_t size, int (*cmp)(const void* a, const void* b));
int ku_introsort(void* array, size_t length, size_t size, int (*cmp)(const void* a, const void* b));
int ku_heapsort(void* array, size_t length, size_t size, int (*cmp)(const void* a, const void* b));

#define ku_sort(array, length, size, cmp) ku_introsort(array, length, size, cmp)

#endif
