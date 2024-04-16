/* This sorting algorithm was pulled from Wikipedia at https://en.wikipedia.org/wiki/Merge_sort#Algorithm on 2024-04-16 18:57:30 EST
 *
 * */

#include "ku_sorting.h"
#include "ku_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int (*comparator)(const void* a, const void* b);
static size_t esize;

static void i_splitmerge(char* b, size_t begin, size_t end, char* a);
static void i_merge(char* b, size_t begin, size_t mid, size_t end, char* a);

int ku_mergesort(void* array, size_t length, size_t element_size, int (*cmp)(const void* a, const void* b)) {
    void* b = malloc(length * element_size);
    if (b == NULL) {
        return -1;
    }

    memcpy(b, array, length * element_size);
    esize = element_size;
    comparator = cmp;
    i_splitmerge((char*)array, 0, length, (char*)b);
    free(b);
    b = NULL;
    return 0;
}

// split the array into 2 smaller arrays, sort them both into b, merge both from b into a
// begin is inclusive, end is exclusive, the range for the array is [begin, end). 
static void i_splitmerge(char* b, size_t begin, size_t end, char* a) {
    // if the array size is 1, consider it sorted
    if (end - begin <= 1)
        return;
    
    // find the midpoint to split the array
    size_t mid = (end + begin) / 2;
    // recursively sort both lists from A into B
    i_splitmerge(a, begin, mid, b);
    i_splitmerge(a, mid, end, b);
    // merge the resulting lists from B into A
    i_merge(b, begin, mid, end, a);
}

static void i_merge(char* b, size_t begin, size_t mid, size_t end, char* a) {
    size_t i = begin;
    size_t j = mid;
    size_t k;
    int cmp_res;
    for(k = begin; k < end; k++) {
        cmp_res = comparator(a + (i*esize), a + (j*esize));
        if (i < mid && (j >= end || cmp_res <= 0)) {
            memcpy(b + (k*esize), a + (i*esize), esize);
            i += 1;
        } else {
            memcpy(b + (k*esize), a + (j*esize), esize);
            j = j + 1; 
        }
    }
}
