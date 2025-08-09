AC_INIT([dsa-for-fun], [0.1.0], [issues@example.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_PROG_CC
dnl Prefer AC_PROG_AR if available, else fall back to AM_PROG_AR
m4_ifdef([AC_PROG_AR], [AC_PROG_AR], [AM_PROG_AR])
AC_PROG_RANLIB

AC_CONFIG_SRCDIR([src/sll/sll.c])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  src/sll/Makefile
  demos/Makefile
  demos/sll/Makefile
])
AC_OUTPUT

