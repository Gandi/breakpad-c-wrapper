TESTS = check_gbc_c_wrapper
check_PROGRAMS = check_gbc_c_wrapper
check_gbc_c_wrapper_SOURCES = check_gbc_c_wrapper.c test_signals.c tests.h $(top_builddir)/include/gbc_c_wrapper.h
check_gbc_c_wrapper_CFLAGS = @CHECK_CFLAGS@  -I ../include
check_gbc_c_wrapper_LDADD = $(top_builddir)/src/libgbc_c_wrapper.la @CHECK_LIBS@
