## -*- Autoconf -*-
#
# Copyright (c) 2008-2011, Vitor Ananjevsky <ananasik@gmail.com>
#
# This file is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# AM_PATH_YAD([MINIMUM-VERSION],[ACTION-IF-FOUND],[ACTION-IF-NOT-FOUND])
# ---------------------------------------------------------------------------
AC_DEFUN([AM_PATH_YAD],[
  m4_if([$1],[],[
    dnl No version check is needed.
    if test -z "$YAD"; then
      AC_PATH_PROG([YAD], yad, :)
    fi
  ], [
    dnl A version check is needed.
    if test -z "$YAD"; then
      AC_PATH_PROG([YAD], yad, :)
    fi
    AC_MSG_CHECKING([whether yad version >= $1])
    m4_define([yad_version],[14.1])
    m4_if(m4_version_compare(yad_version,[$1]),[-1],
      [AC_MSG_ERROR([too old (]yad_version[)])],
      [AC_MSG_RESULT(yad_version)])
  ])

  if test "$YAD" = :; then
    dnl Run any user-specified action, or abort.
    m4_default([$3], [AC_MSG_ERROR([Yad not found])])
  else
    dnl Run any user-specified action.
    m4_if([$2],[],[true],[$2])
    AC_SUBST([YAD])
  fi
])
