lib_LTLIBRARIES = libgbc_c_wrapper.la
lib_LIBRARIES = libgbc_c_wrapper.a
libgbc_c_wrapper_la_SOURCES = gbc_c_wrapper.cc
libgbc_c_wrapper_la_CXXPPFLAGS = $(BREAKPAD_CLIENT_CPPFLAGS) -I ../include
libgbc_c_wrapper_la_CXXFLAGS = $(AM_CXXFLAGS) $(BREAKPAD_CLIENT_CFLAGS) -I ../include
libgbc_c_wrapper_la_LIBADD = $(BREAKPAD_CLIENT_LIBS)

libgbc_c_wrapper_a_SOURCES = gbc_c_wrapper.cc
libgbc_c_wrapper_a_CXXPPFLAGS = $(BREAKPAD_CLIENT_CPPFLAGS) -I ../include
libgbc_c_wrapper_a_CXXFLAGS = $(AM_CXXFLAGS) $(BREAKPAD_CLIENT_CFLAGS) -I ../include
libgbc_c_wrapper_a_LDLAGS = $(BREAKPAD_CLIENT_LIBS)
