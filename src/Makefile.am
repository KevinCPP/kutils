AUTOMAKE_OPTIONS = subdir-objects

ALGO_DIR = algorithms
DS_DIR = data_structures

ALGO_SRCS = $(ALGO_DIR)/sorting/ku_insertionsort.c \
			$(ALGO_DIR)/sorting/ku_mergesort.c \
			$(ALGO_DIR)/searching/ku_binarysearch.c \
			$(ALGO_DIR)/util/ku_comparators.c \
			$(ALGO_DIR)/util/ku_swap.c

DS_SRCS = $(DS_DIR)/ku_vec.c

ALL_SRCS = $(ALGO_SRCS) $(DS_SRCS)

# combine all sources
libdsa_la_SOURCES = $(ALL_SRCS)
# Additional flags for linking shared
libdsa_la_LDFLAGS = -shared

# include directories for the compiler
AM_CFLAGS = -Wall -I$(top_srcdir)/include \
			-I$(top_srcdir)/include/algorithms \
			-I$(top_srcdir)/include/data_structures \
			-I$(top_srcdir)/include/external \
			-std=c11 \
			-D_POSIX_C_SOURCE=200809L

# define shared library
lib_LTLIBRARIES = libdsa.la
