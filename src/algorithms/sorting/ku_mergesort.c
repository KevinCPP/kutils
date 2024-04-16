/* This sorting algorithm was pulled from Wikipedia at https://en.wikipedia.org/wiki/Merge_sort#Algorithm on 2024-04-16 18:57:30 EST
 * Much of the comments throughout this file were directly pulled from the wikipedia pseudocode as well. When the phrase "runs" is used
 * it is referring to one of the sublists that was divided / sorted
 *
 * This uses the "top down" implementation that was listed in the wikipedia article.
 *
*/

#include "ku_sorting.h"
#include "ku_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// store the comparator and element size in static variables to 
// avoid constantly passing them in the recursive function calls.
static int (*comparator)(const void* a, const void* b);
static size_t esize;

// forward declaration of these two internal functions. For the purposes of this
// project, the i_ prefix before a static function's name is going to mean "Internal"
static void i_splitmerge(char* b, size_t begin, size_t end, char* a);
static void i_merge(char* b, size_t begin, size_t mid, size_t end, char* a);

// publicly visible mergesort function
int ku_mergesort(void* array, size_t length, size_t element_size, int (*cmp)(const void* a, const void* b)) {
    // allocate memory for the work array
    void* b = malloc(length * element_size);
    // error checking
    if (b == NULL) {
        return -1;
    }
    // copy the input array into the work array
    memcpy(b, array, length * element_size);
    // set the static variables (element size and comarator)
    esize = element_size;
    comparator = cmp;
    // call the internal merge sort "divide" function
    i_splitmerge((char*)array, 0, length, (char*)b);
    // free the work array and set it to NULL
    free(b);
    b = NULL; // this is somewhat redundant but why not
    // success
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

// this is the merge step, the left source half is A[begin:mid-1],
// the right source half is A[mid:end-1], and the result will be
// B[begin:end-1]
static void i_merge(char* b, size_t begin, size_t mid, size_t end, char* a) {
    size_t i = begin;
    size_t j = mid;
    size_t k;
    int cmp_res;
    // while there are elements in the left/right runs
    for(k = begin; k < end; k++) {
        // if the left run head exists and is <= existing right run head
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
