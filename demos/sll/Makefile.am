# One demo binary for SLL
bin_PROGRAMS = sll_demo
sll_demo_SOURCES = main.c

# Link only with libsll.a from src/sll
sll_demo_LDADD = $(top_builddir)/src/sll/libsll.a

AM_CPPFLAGS = -I$(top_srcdir)/include
AM_CFLAGS   = -std=c11 -Wall -Wextra -Wpedantic -O2

