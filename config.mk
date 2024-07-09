# comb version
VERSION = 0.1

# paths
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

# includes and libs
INCS =
LIBS =

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"$(VERSION)\"
CFLAGS   = -std=c99 -pedantic -Wall -Os $(INCS) $(CPPFLAGS)
LDFLAGS  = $(LIBS)

# compiler and linker
#CC = cc
