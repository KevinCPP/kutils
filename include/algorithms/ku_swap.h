#ifndef SWAP_H
#define SWAP_H

#include <stddef.h>

// I chose this number arbitrarily, essentially, when using generic_swap, it will choose to use the
// stack rather than the heap for any data types that are <= 256 bytes
#define MAX_STACK_BUFFER 256

int ku_generic_swap(void* a, void* b, size_t size);
int ku_generic_swap_heap(void* a, void* b, size_t size);
int ku_generic_swap_stack(void* a, void* b, size_t size);


#endif
