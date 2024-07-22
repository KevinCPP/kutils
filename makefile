CC = gcc
CFLAGS = -Wall -Iinclude -Og -Iinclude/algorithms -Iinclude/data_structures -Iinclude/external -std=c11 -D_POSIX_C_SOURCE=200809L
LDFLAGS =
SRCDIR = src
OBJDIR = obj
BINDIR = bin
LIBDIR = lib
TESTDIR = tests

# recursively find all .c files in the source directory
SOURCES := $(shell find $(SRCDIR) -name '*.c')
# transform list of source files to object files by replacing directory and extensions
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Find all test files
TEST_SOURCES := $(wildcard $(TESTDIR)/*.c)
TESTS := $(TEST_SOURCES:$(TESTDIR)/%.c=$(BINDIR)/%)

# default target
all: directories lib $(TESTS)

# Library compilation target
libstatic: directories $(OBJECTS)
	ar rcs $(LIBDIR)/libdsa.a $(OBJECTS)

libshared: directories $(OBJECTS)
	gcc -shared -o $(LIBDIR)/libdsa.so $(OBJECTS) $(LDFLAGS)

lib: libstatic libshared

# create directories based on found sources
directories:
	@mkdir -p $(sort $(dir $(OBJECTS))) $(BINDIR) $(LIBDIR)

# Compile tests
$(BINDIR)/%: $(TESTDIR)/%.c $(OBJECTS)
	$(CC) $(CFLAGS) $< $(OBJECTS) -o $@ $(LDFLAGS)

# compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR) $(LIBDIR)

.PHONY: all clean directories
