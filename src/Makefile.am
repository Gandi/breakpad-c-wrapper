lib_LTLIBRARIES = libgbc_c_wrapper.la
libgbc_c_wrapper_la_SOURCES = gbc_c_wrapper.cc

libgbc_c_wrapper_la_CXXPPFLAGS = $(BREAKPAD_CLIENT_CPPFLAGS) -I ../include
libgbc_c_wrapper_la_CXXFLAGS = $(AM_CXXFLAGS) $(BREAKPAD_CLIENT_CFLAGS) -I ../include

libgbc_c_wrapper_la_LIBADD = $(BREAKPAD_CLIENT_LIBS)
