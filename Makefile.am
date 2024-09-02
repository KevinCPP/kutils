# define project source directories
SRCDIR = src
ALGO_DIR = $(SRCDIR)/algorithms
DS_DIR = $(SRCDIR)/data_structures

ALGO_SRCS = $(ALGO_DIR)/sorting/ku_insertionsort.c \
			$(ALGO_DIR)/sorting/ku_mergesort.c \
			$(ALGO_DIR)/searching/ku_binarysearch.c \
			$(ALGO_DIR)/util/ku_comparators.c \
			$(ALGO_DIR)/util/ku_swap.c

DS_SRCS = $(DS_DIR)/ku_vec.c

ALL_SRCS = $(ALGO_SRCS) $(DS_SRCS)

# combine all sources
lib_libdsa_la_SOURCES = $(ALL_SRCS)

# define shared library
lib_LTLIBRARIES = lib/libdsa.la

# Additional flags for linking shared
lib_libdsa_la_LDFLAGS = -shared

# include directories for the compiler
AM_CFLAGS = -Wall -Iinclude -Iinclude/algorithms -Iinclude/data_structures -Iinclude/external -std=c11 -D_POSIX_C_SOURCE=200809L
ACLOCAL_AMFLAGS = -I m4
##### WILL REMOVE #####
# Test Programs
TESTS = bin/test_sorting bin/test_swap bin/test_vec
check_PROGRAMS = $(TESTS)

# sources for test programs
bin_test_sorting_SOURCES = tests/test_sorting.c
bin_test_swap_SOURCES = tests/test_swap.c
bin_test_vec_SOURCES = tests/test_vec.c

# Link test programs with the library
bin_test_sorting_LDADD = lib/libdsa.a
bin_test_swap_LDADD = lib/libdsa.a
bin_test_vec_LDADD = lib/libdsa.a

# clean up files created during the build
clean-local:
	rm -rf $(TESTS)

.PHONY: clean-local
