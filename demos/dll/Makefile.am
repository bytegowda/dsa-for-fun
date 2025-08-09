# One demo binary for DLL
bin_PROGRAMS = dll_demo
dll_demo_SOURCES = main.c

# Link only with libdll.a from src/dll
dll_demo_LDADD = $(top_builddir)/src/dll/libdll.a

AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CFLAGS   = -std=c11 -Wall -Wextra -Wpedantic -O2

