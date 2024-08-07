#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ku_vec.h"
#include "ku_sorting.h"

void print_int_arr(const int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_int_vec(const ku_vec* vec) {
    size_t len = ku_vec_length(vec);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        printf("%d ", *vec_at_i);
        free(vec_at_i);
        vec_at_i = NULL;
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
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        assert(*vec_at_i == expected[i]); // Validate each element
        free(vec_at_i);
        vec_at_i = NULL;
    }

    ku_vec_destroy(&vec); // Free allocated memory

    printf("SUCCESS! END OF test_append()\n\n");
}

void test_set() {
    ku_vec* vec = ku_vec_create(sizeof(int));
    int myarr[10] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, myarr, 10);
    
    int x = 4;
    ku_vec_set(vec, 3, &x);
    myarr[3] = x;
    
    size_t len = ku_vec_length(vec);
    assert(len == 10);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        assert(*vec_at_i == myarr[i]);
        free(vec_at_i);
        vec_at_i = NULL;
    }

    ku_vec_destroy(&vec);
    printf("SUCCESS! END OF test_set()\n\n");
}

void test_push() {
    ku_vec* vec = ku_vec_create(sizeof(int));
    int myarr[10] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
   
    for (size_t i = 0; i < 100; i++) {
        ku_vec_push(vec, &myarr[i % 10]);
    }

    size_t len = ku_vec_length(vec);
    assert(len == 100);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        assert(*vec_at_i == myarr[i % 10]);
        free(vec_at_i);
        vec_at_i = NULL;
    }

    ku_vec_destroy(&vec);
    printf("SUCCESS! END OF test_push()\n\n");
}

int cmp_int(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    else if (x > y) return 1;
    else return 0;
}

void test_get_data_ptr() {
    ku_vec* vec = ku_vec_create(sizeof(int));
    int myarr[10] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, myarr, 10);
   
    ku_mergesort((void*)myarr, 10, sizeof(int), cmp_int);    
    
    void* vec_data = ku_vec_get_data_ptr(vec);
    ku_mergesort(vec_data, 10, sizeof(int), cmp_int);

    size_t len = ku_vec_length(vec);
    assert(len == 10);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        assert(*vec_at_i == myarr[i]);
        printf("%d ", *vec_at_i);
        free(vec_at_i);
        vec_at_i = NULL;
    }
    printf("\n");

    ku_vec_destroy(&vec);
    printf("SUCCESS! END OF test_get_data_ptr()\n\n");
}

void test_pop() {
    ku_vec* vec = ku_vec_create(sizeof(int));
    int myarr[10] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, myarr, 10);
    
    for (size_t i = 0; i < 64; i++)
        free(ku_vec_pop(vec));

    size_t len = ku_vec_length(vec);
    assert(len == 0);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        assert(*vec_at_i == myarr[i]);
        free(vec_at_i);
        vec_at_i = NULL;
    }
    
    ku_vec_destroy(&vec);
    printf("SUCCESS! END OF test_pop()\n\n");
}

int main() {
    test_append();
    test_set();
    test_push();
    test_get_data_ptr();
    test_pop();
    return 0;
}

