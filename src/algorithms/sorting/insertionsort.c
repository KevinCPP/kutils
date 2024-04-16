#include "ku_sorting.h"
#include "ku_swap.h"

int ku_insertionsort(void* array, size_t length, size_t element_size, int (*cmp)(const void* a, const void* b)) {
    unsigned char* arr = (unsigned char*)array;
    size_t i, j;

    for (i = element_size; i < length*element_size; i += element_size) {
        j = i;
        while((j > 0) && cmp(arr + (j-element_size), arr + j) > 0) {
            if(ku_generic_swap(arr + (j-element_size), arr + j, element_size) != 0)
                return -1;

            j -= element_size;
        }
    }

    return 0;
}
