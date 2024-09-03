TESTS = bin/check_vec
check_PROGRAMS = bin/check_vec

bin_check_vec_SOURCES = check_vec.c
bin_check_vec_CFLAGS = -I$(top_srcdir)/include \
					   -I$(top_srcdir)/include/algorithms \
					   -I$(top_srcdir)/include/data_structures \
					   @CHECK_CFLAGS@

bin_check_vec_LDADD = $(top_srcdir)/src/libdsa.la @CHECK_LIBS@
