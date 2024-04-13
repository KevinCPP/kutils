#include <stdio.h>
#include <assert.h>

#include "vec.h"


void print_int_arr(const int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_int_vec(const ku_vec* vec) {
    size_t len = ku_vec_length(vec);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", *((int*)ku_vec_get(vec, i)));
    }
    printf("\n");
}

void test_append() {
    ku_vec* vec = ku_vec_create(sizeof(int));
    int myarr[10] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, myarr, 10);
    ku_vec_append(vec, myarr, 10);

    int expected[20] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9, 1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    size_t len = ku_vec_length(vec);
    assert(len == 20); // Check the length first

    for (size_t i = 0; i < len; i++) {
        int vec_at_i = *((int*)ku_vec_get(vec, i));
        assert(vec_at_i == expected[i]); // Validate each element
    }

    ku_vec_destroy(&vec); // Free allocated memory

    printf("SUCCESS! END OF test_append()\n\n");
}

int main() {
    test_append();
    return 0;
}

