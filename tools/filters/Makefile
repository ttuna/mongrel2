PREFIX?=/usr/local

ifneq ($(uname_O),Cygwin)
CFLAGS=-I../../src -I../../src/mbedtls/include $(OPTFLAGS) -g -fPIC -shared -nostartfiles -L../../build
else
CFLAGS=-I../../src -I../../src/mbedtls/include $(OPTFLAGS) -g -shared -nostartfiles -L../../build
endif
LDFLAGS=$(OPTLIBS)

all: null.so rewrite.so sendfile.so

%.so : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $< ../../build/libm2.a

clean:
	rm -f *.so

install:
#	install -d $(DESTDIR)/$(PREFIX)/lib/mongrel2/filters/
#	install *.so $(DESTDIR)/$(PREFIX)/lib/mongrel2/filters/
	install -d $(PREFIX)/lib/mongrel2/filters/
	install *.so $(PREFIX)/lib/mongrel2/filters/
