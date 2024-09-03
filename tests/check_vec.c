#include <stdio.h>
#include <check.h>
#include <stdlib.h>

#include "include/data_structures/ku_vec.h"
#include "include/algorithms/ku_sorting.h"

#define VALUES_LEN (size_t)10

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

START_TEST(test_append)
{
    const char* prefix = "[tests/check_vec.c:test_append] ";

    ku_vec* vec = ku_vec_create(sizeof(int));
    int values[VALUES_LEN] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, values, VALUES_LEN);
    ku_vec_append(vec, values, VALUES_LEN);

    int expected[(VALUES_LEN*2)] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9, 1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    size_t len = ku_vec_length(vec);
    ck_assert_msg(len == (VALUES_LEN*2), 
        "%sFAILED: ku_vec has incorrect length after append operations! Expected: %lu, Found %lu", prefix, (VALUES_LEN*2), len); // Check the length first

    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        ck_assert_msg(*vec_at_i == expected[i], 
            "%sFAILED: ku_vec failed element validation after assert operation! ku_vec_length: %lu, invalid element index: %lu, Expected: %d, Found: %d", prefix, len, i, expected[i], *vec_at_i); // Validate each element
        free(vec_at_i);
        vec_at_i = NULL;
    }

    ku_vec_destroy(&vec); // Free allocated memory

    // printf("SUCCESS! END OF test_append()\n\n");
}
END_TEST

START_TEST(test_set) 
{
    const char* prefix = "[tests/check_vec.c:test_set] ";

    ku_vec* vec = ku_vec_create(sizeof(int));
    int values[VALUES_LEN] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, values, VALUES_LEN);
    
    int x = 4;
    ku_vec_set(vec, 3, &x);
    values[3] = x;
    
    size_t len = ku_vec_length(vec);
    ck_assert_msg(len == VALUES_LEN, "%sFAILED: ku_vec has incorrect length after append and set operations! Expected %lu, Found %lu", prefix, VALUES_LEN, len);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        ck_assert_msg(*vec_at_i == values[i], "%sFAILED: ku_vec has incorrect element after set operation! Expected Index: %lu, Found Index: %lu, Expected Value: %d, Found Value: %d", prefix, (size_t)3, i, values[3], *vec_at_i);
        free(vec_at_i);
        vec_at_i = NULL;
    }

    ku_vec_destroy(&vec);
    //printf("SUCCESS! END OF test_set()\n\n");
}
END_TEST

START_TEST(test_push) 
{
    const char* prefix = "[tests/check_vec.c:test_push] ";
    const size_t num_push_ops = 100;

    ku_vec* vec = ku_vec_create(sizeof(int));
    
    int values[VALUES_LEN] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
   
    for (size_t i = 0; i < num_push_ops; i++) {
        ku_vec_push(vec, &values[i % VALUES_LEN]);
    }

    size_t len = ku_vec_length(vec);
    ck_assert_msg(len == num_push_ops, "%sFAILED: ku_vec has incorrect length after push operations! Expected: %lu, Found: %lu", prefix, num_push_ops, len);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        ck_assert_msg(*vec_at_i == values[i % VALUES_LEN], "%sFAILED: ku_vec has incorrect element after push operation! Index: %lu, Expected Value: %d, Found Value: %d", prefix, i, values[i % VALUES_LEN], *vec_at_i);
        free(vec_at_i);
        vec_at_i = NULL;
    }

    ku_vec_destroy(&vec);
    //printf("SUCCESS! END OF test_push()\n\n");
}
END_TEST

int cmp_int(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    else if (x > y) return 1;
    else return 0;
}

START_TEST(test_get_data_ptr) 
{
    const char* prefix = "[tests/check_vec.c:test_get_data_ptr] ";
    ku_vec* vec = ku_vec_create(sizeof(int));
    int values[VALUES_LEN] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, values, VALUES_LEN);
   
    ku_mergesort((void*)values, VALUES_LEN, sizeof(int), cmp_int);    
    
    void* vec_data = ku_vec_get_data_ptr(vec);
    ku_mergesort(vec_data, VALUES_LEN, sizeof(int), cmp_int);

    size_t len = ku_vec_length(vec);
    ck_assert_msg(len == VALUES_LEN, "%sFAILED: ku_vec has incorrect length after using test_get_data_ptr to sort the vector! Expected: %lu, Found: %lu", prefix, VALUES_LEN, len);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        ck_assert_msg(*vec_at_i == values[i], "%sFAILED: ku_vec has incorrect element after test_get_data_ptr to sort the vector! Index: %lu, Expected: %d, Found: %d", prefix, i, values[i], *vec_at_i);
        // printf("%d ", *vec_at_i);
        free(vec_at_i);
        vec_at_i = NULL;
    }
    // printf("\n");

    ku_vec_destroy(&vec);
    // printf("SUCCESS! END OF test_get_data_ptr()\n\n");
} 
END_TEST

START_TEST(test_pop) 
{
    const char* prefix = "[tests/check_vec.c:test_pop] ";
    ku_vec* vec = ku_vec_create(sizeof(int));
    int myarr[10] = {1, 2, 3, 8, 6, 7, 5, 3, 0, 9};
    ku_vec_append(vec, myarr, 10);
    
    for (size_t i = 0; i < 64; i++)
        free(ku_vec_pop(vec));

    size_t len = ku_vec_length(vec);
    // should be zero, set to 2 to intentionally fail
    ck_assert_msg(len == 0, "%sFAILED: ku_vec has incorrect length after pop operations! Expected: %lu, Found: %lu", prefix, (size_t)0, len);
    for (size_t i = 0; i < len; i++) {
        int* vec_at_i = (int*)ku_vec_get(vec, i);
        ck_assert_msg(*vec_at_i == myarr[i], "%sFAILED: ku_vec has incorrect element after pop operations! Index: %lu, Expected: %d, Found: %d", prefix, i, myarr[i], *vec_at_i);
        free(vec_at_i);
        vec_at_i = NULL;
    }
    
    ku_vec_destroy(&vec);
    // printf("SUCCESS! END OF test_pop()\n\n");
} 
END_TEST

Suite *vec_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("ku_vec");
    
    // core test case
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_append);
    tcase_add_test(tc_core, test_set);
    tcase_add_test(tc_core, test_push);
    tcase_add_test(tc_core, test_get_data_ptr);
    tcase_add_test(tc_core, test_pop);
    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    int number_failed = 0;
    Suite *s;
    SRunner *sr;

    s = vec_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

