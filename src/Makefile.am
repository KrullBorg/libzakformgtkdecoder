if PLATFORM_WIN32
libmodulesext = -0.dll
libmodulesdir = $(bindir)
else
libmodulesext = .so
libmodulesdir = $(libdir)
endif

libzakformmodulesdir = `pkg-config --variable=modulesdir libzakform`

LIBS = $(ZAKFORMGTKDECODER_LIBS)

AM_CPPFLAGS = $(ZAKFORMGTKDECODER_CFLAGS) \
              -DLOCALEDIR=\"$(localedir)\" \
              -DG_LOG_DOMAIN=\"ZakFormGtkDecoder\"

lib_LTLIBRARIES = libzakformgtkdecoder.la

libzakformgtkdecoder_la_SOURCES = \
                        formelementdecoder.c

libzakformgtkdecoder_la_LDFLAGS = -no-undefined

libzakformgtkdecoder_include_HEADERS = \
                             libzakformgtkdecoder.h \
                             formelementdecoder.h

libzakformgtkdecoder_includedir = $(includedir)/libzakformgtkdecoder

install-exec-hook:
	cd $(libzakformmodulesdir) && \
	ln -s -f $(libmodulesdir)/libzakformgtkdecoder$(libmodulesext) .

uninstall-hook:
	rm -f $(libzakformmodulesdir)/libzakformgtkdecoder$(libmodulesext)
