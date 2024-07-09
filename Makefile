# comb - combination generator with non-combinable selections
# See LICENSE file for copyright and license details.

include config.mk

SRC = comb.c
OBJ = $(SRC:.c=.o)

all: comb

.c.o:
	$(CC) -c $(CFLAGS) $<

comb: comb.o
	$(CC) -o $@ comb.o $(LDFLAGS)

clean:
	rm -f comb $(OBJ) comb-$(VERSION).tar.gz

dist: clean
	mkdir -p comb-$(VERSION)
	cp LICENSE Makefile ${SRC} comb.1 config.mk comb-$(VERSION)
	tar -cf comb-$(VERSION).tar comb-$(VERSION)
	gzip comb-$(VERSION).tar
	rm -rf comb-$(VERSION)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f comb $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/comb
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < comb.1 > ${DESTDIR}${MANPREFIX}/man1/comb.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/comb.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/comb\
	      ${DESTDIR}${MANPREFIX}/man1/comb.1

.PHONY: all clean dist install uninstall
