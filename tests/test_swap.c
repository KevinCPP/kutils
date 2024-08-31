// include stdio.h for access to printf
#include <stdio.h>
// include ku_swap.h for access to the swap functions
#include "ku_swap.h"

int main() {
    // two variables to be swapped
    int a = 10;
    int b = 5;
    
    // generic swap function will use stack in this case since MAX_STACK_BUFFER 
    // is 256, and `sizeof(int)` will return either 4 or 8 depending on the system.
    // (void*)(&a) casts a reference to `a` into a void*, which is what the function 
    // parameter expects. Same for `b`.
    int err = ku_generic_swap((void*)(&a), (void*)(&b), sizeof(int));

    // handle any potential error that is returned
    if (err != 0)
        fprintf(stderr, "Error: ku_generic_swap failed!");

    // should print "5, 10"
    printf("%d %d\n", a, b);

    // swap function using the heap
    err = ku_generic_swap_heap((void*)(&a), (void*)(&b), sizeof(int));

    // handle any potential error that is returned
    if (err != 0)
        fprintf(stderr, "Error: ku_generic_swap_heap failed!");

    // should print "10, 5"
    printf("%d %d\n", a, b);

    return 0;
}
