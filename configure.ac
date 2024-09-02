### Prelude

# Require mandatory autoconf initialization
AC_INIT([kutil], [indev], [kevinncosby2@gmail.com])

# AC_CONFIG_AUX_DIR([DIRECTORY]) Auxilary Scripts such as `install-sh`
# and `depcomp` should be in `DIRECTORY`.
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIRS([m4])

# need to initialize automake as well
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])

# AC_CONFIG_SRCDIR(FILE) -- sanity check. FILE should be a source file, this
# makes sure that `configure` is not run from "outer space".
AC_CONFIG_SRCDIR([src/data_structures/ku_vec.c])

### Program Checks
# will check to ensure we have a C compiler, e.g. gcc
AC_PROG_CC
AM_PROG_AR
# AC_PROG_RANLIB
LT_INIT

# Checks for libraries
# ...
# Checks for header files
# ...
# Checks for typedefs, structures, and compiler characteristics
# ...
# Checks for library functions
# ...
# Output files
# AC_CONFIG_HEADERS([config.h])

# will generate a makefile
AC_CONFIG_FILES([Makefile])
# outputs any config files
AC_OUTPUT
