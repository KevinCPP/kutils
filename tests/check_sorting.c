#include <stdlib.h>
#include <stddef.h>
#include <check.h>

#include "include/algorithms/ku_sorting.h"
#include "include/algorithms/ku_comparators.h"

#define INORDER_LENGTH 10
#define INORDER_TYPE int
#define INORDER_COMPARATOR ku_int_cmp
#define INORDER {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
#define INORDER_EXPECTED {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

#define REVERSED_LENGTH 10
#define REVERSED_TYPE int
#define REVERSED_COMPARATOR ku_int_cmp
#define REVERSED {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
#define REVERSED_EXPECTED {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

#define DUPLICATE_LENGTH 10
#define DUPLICATE_TYPE int
#define DUPLICATE_COMPARATOR ku_int_cmp
#define DUPLICATE {8, 8, 9, 5, 6, 7, 1, 2, 0, 3}
#define DUPLICATE_EXPECTED {0, 1, 2, 3, 5, 6, 7, 8, 8, 9}

#define ALLSAME_LENGTH 10
#define ALLSAME_TYPE int
#define ALLSAME_COMPARATOR ku_int_cmp
#define ALLSAME {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
#define ALLSAME_EXPECTED {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

#define SINGLE_LENGTH 1
#define SINGLE_TYPE int
#define SINGLE_COMPARATOR ku_int_cmp
#define SINGLE {2147483647}
#define SINGLE_EXPECTED {2147483647}

#define TEST_BODY(test_func) \
do { \
    const char* prefix = "[tests/check_sorting.c:test_mergesort] "; \
    SINGLE_TYPE single[SINGLE_LENGTH] = SINGLE; \
    SINGLE_TYPE single_expected[SINGLE_LENGTH] = SINGLE_EXPECTED; \
\
    ALLSAME_TYPE allsame[ALLSAME_LENGTH] = ALLSAME; \
    ALLSAME_TYPE allsame_expected[ALLSAME_LENGTH] = ALLSAME_EXPECTED; \
\
    INORDER_TYPE inorder[INORDER_LENGTH] = INORDER; \
    INORDER_TYPE inorder_expected[INORDER_LENGTH] = INORDER_EXPECTED; \
\
    REVERSED_TYPE reversed[REVERSED_LENGTH] = REVERSED; \
    REVERSED_TYPE reversed_expected[REVERSED_LENGTH] = REVERSED_EXPECTED; \
\
    DUPLICATE_TYPE duplicate[DUPLICATE_LENGTH] = DUPLICATE; \
    DUPLICATE_TYPE duplicate_expected[DUPLICATE_LENGTH] = DUPLICATE_EXPECTED; \
\
    test_func((void*)single, SINGLE_LENGTH, sizeof(SINGLE_TYPE), SINGLE_COMPARATOR); \
    test_func((void*)allsame, ALLSAME_LENGTH, sizeof(ALLSAME_TYPE), ALLSAME_COMPARATOR); \
    test_func((void*)inorder, INORDER_LENGTH, sizeof(INORDER_TYPE), INORDER_COMPARATOR); \
    test_func((void*)reversed, REVERSED_LENGTH, sizeof(REVERSED_TYPE), REVERSED_COMPARATOR); \
    test_func((void*)duplicate, DUPLICATE_LENGTH, sizeof(DUPLICATE_TYPE), DUPLICATE_COMPARATOR); \
\
    ck_assert_mem_eq(single, single_expected, SINGLE_LENGTH); \
    ck_assert_mem_eq(allsame, allsame_expected, ALLSAME_LENGTH); \
    ck_assert_mem_eq(inorder, inorder_expected, INORDER_LENGTH); \
    ck_assert_mem_eq(reversed, reversed_expected, REVERSED_LENGTH); \
    ck_assert_mem_eq(duplicate, duplicate_expected, DUPLICATE_LENGTH); \
} while(0)

START_TEST(test_mergesort)
{
    TEST_BODY(ku_mergesort);
}
END_TEST 


START_TEST(test_insertionsort)
{
    TEST_BODY(ku_insertionsort);
}
END_TEST

Suite *vec_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("ku_sorting");
    
    // core test case
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_mergesort);
    tcase_add_test(tc_core, test_insertionsort);
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
