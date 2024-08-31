#include <stdlib.h>
#include <string.h>

#include "ku_swap.h"

int ku_generic_swap(void* a, void* b, size_t size) {
    if (size <= MAX_STACK_BUFFER) {
        return ku_generic_swap_stack(a, b, size);
    } else {
        return ku_generic_swap_heap(a, b, size);
    }
}

// will use the stack to swap via VLAs
int ku_generic_swap_stack(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    return 0;
}

// will use the heap to swap via malloc
int ku_generic_swap_heap(void* a, void* b, size_t size) {
    void* temp = malloc(size);
    if (temp == NULL)
        return -1;

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
    temp = NULL;
    return 0;
}


