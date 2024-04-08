#ifndef SORTING_H
#define SORTING_H

#include <stddef.h>

// various sorting algorithms that can be specifically chosen by the user
void ku_insertionsort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))
void ku_countingsort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))
void ku_mergesort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))
void ku_quicksort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))
void ku_radixsort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))
void ku_introsort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))
void ku_heapsort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))

// a simple "sort" function so the user doesn't have to decide (will just automatically use introsort)
void ku_sort(void* array, size_t length, size_t element_size, int (*less_than)(void* a, void* b))

#endif
