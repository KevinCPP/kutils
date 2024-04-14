#include "ku_sorting.h"
#include "ku_swap.h"

void ku_insertionsort(void* array, size_t length, size_t element_size, int (*cmp)(void* a, void* b)) {
    unsigned char* arr = (unsigned char*)array;
    size_t i, j;

    for (i = element_size; i < length*element_size; i += element_size) {
        j = i;
        while((j > 0) && cmp(arr + (j-element_size), arr + j) > 0) {
            ku_generic_swap(arr + (j-element_size), arr + j, element_size);
            j -= element_size;
        }
    }
}
