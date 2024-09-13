TESTS = bin/check_vec bin/check_sorting bin/check_string
check_PROGRAMS = bin/check_vec bin/check_sorting bin/check_string

bin_check_vec_SOURCES = check_vec.c
bin_check_vec_CFLAGS = -I$(top_srcdir)/include \
					   -I$(top_srcdir)/include/algorithms \
					   -I$(top_srcdir)/include/data_structures \
					   @CHECK_CFLAGS@

bin_check_sorting_SOURCES = check_sorting.c
bin_check_sorting_CFLAGS = -I$(top_srcdir)/include \
					   -I$(top_srcdir)/include/algorithms \
					   -I$(top_srcdir)/include/data_structures \
					   @CHECK_CFLAGS@

bin_check_string_SOURCES = check_string.c
bin_check_string_CFLAGS = -I$(top_srcdir)/include \
					   -I$(top_srcdir)/include/algorithms \
					   -I$(top_srcdir)/include/data_structures \
					   @CHECK_CFLAGS@

bin_check_vec_LDADD = $(top_srcdir)/src/libdsa.la @CHECK_LIBS@
bin_check_sorting_LDADD = $(top_srcdir)/src/libdsa.la @CHECK_LIBS@
bin_check_string_LDADD = $(top_srcdir)/src/libdsa.la @CHECK_LIBS@
