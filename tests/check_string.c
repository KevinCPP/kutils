#include <stdio.h>
#include <check.h>
#include <stdlib.h>

#include "include/data_structures/ku_string.h"

#define PREFIX(test_name) "[tests/check_string.c:" test_name "] "

START_TEST(check_set) 
{
    const char* prefix = PREFIX("check_set");
}
END_TEST


START_TEST(check_append) 
{
    const char* prefix = PREFIX("check_append");
}
END_TEST


START_TEST(check_get) 
{
    const char* prefix = PREFIX("check_get");
}
END_TEST

START_TEST(check_delete) 
{
    const char* prefix = PREFIX("check_delete");
}
END_TEST

START_TEST(check_reserve) 
{
    const char* prefix = PREFIX("check_reserve");
}
END_TEST

START_TEST(check_push) 
{
    const char* prefix = PREFIX("check_push");
}
END_TEST

START_TEST(check_capacity) 
{
    const char* prefix = PREFIX("check_capacity");
}
END_TEST

START_TEST(check_length) 
{
    const char* prefix = PREFIX("check_length");
}
END_TEST

START_TEST(check_get_data_ptr) 
{
    const char* prefix = PREFIX("check_get_data_ptr");
}
END_TEST

START_TEST(check_pop) 
{
    const char* prefix = PREFIX("check_pop");
}
END_TEST

Suite *string_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("ku_string");
    
    // core test case
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, check_append);
    suite_add_tcase(s, tc_core);
    return s;
}

int main() {
    int number_failed = 0;
    Suite *s;
    SRunner *sr;

    s = string_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
