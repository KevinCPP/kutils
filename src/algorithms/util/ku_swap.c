#include <stdlib.h>
#include <string.h>

#include "ku_swap.h"

void ku_generic_swap(void* a, void* b, size_t size) {
    if (size <= MAX_STACK_BUFFER) {
        ku_generic_swap_stack(a, b, size);
    } else {
        ku_generic_swap_heap(a, b, size);
    }
}

// will use the stack to swap via VLAs
void ku_generic_swap_stack(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// will use the heap to swap via malloc
void ku_generic_swap_heap(void* a, void* b, size_t size) {
    void* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}
