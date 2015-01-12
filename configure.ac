AC_INIT([gbc_c_wrapper], [0.1], [nikita@elyzion.net])
AM_INIT_AUTOMAKE([-Wall -W foreign subdir-objects])

AM_PROG_AR
AC_PROG_CXX_C_O

AC_CONFIG_MACRO_DIRS([m4])

LT_INIT
m4_include(m4/ax_pthread.m4)
AX_PTHREAD

AC_CONFIG_FILES([
 gbc_c_wrapper.pc
 Makefile
 src/Makefile
 include/Makefile
])

PKG_CHECK_MODULES([BREAKPAD_CLIENT], [breakpad-client])

###############################################################################
# If using GCC, set some additional AM_CFLAGS:
###############################################################################

if test "$GCC" = yes ; then
        echo
        echo "GCC extensions:"
fi

# Always do the visibility check but don't set AM_CFLAGS on Windows.
# This way things get set properly even on Windows.
gl_VISIBILITY
if test -n "$CFLAG_VISIBILITY" && test "$is_w32" = no; then
        AM_CFLAGS="$AM_CFLAGS $CFLAG_VISIBILITY"
fi

if test "$GCC" = yes ; then
        # Enable as much warnings as possible. These commented warnings won't
        # work for this package though:
        #   * -Wunreachable-code breaks several assert(0) cases, which are
        #     backed up with "return LZMA_PROG_ERROR".
        #   * -Wcast-qual would break various things where we need a non-const
        #     pointer although we don't modify anything through it.
        #   * -Wcast-align breaks optimized CRC32 and CRC64 implementation
        #     on some architectures (not on x86), where this warning is bogus,
        #     because we take care of correct alignment.
        #   * -Winline, -Wdisabled-optimization, -Wunsafe-loop-optimizations
        #     don't seem so useful here; at least the last one gives some
        #     warnings which are not bugs.
        for NEW_FLAG in \
                        -Wall \
                        -Wextra \
                        -Wformat=2 \
                        -Winit-self \
                        -Wmissing-include-dirs \
                        -Wstrict-aliasing \
                        -Wfloat-equal \
                        -Wundef \
                        -Wpointer-arith \
                        -Wwrite-strings \
                        -Wlogical-op \
                        -Waggregate-return \
                        -Wmissing-declarations \
                        -Wmissing-noreturn 
#                        -Wredundant-decls
        do
                AC_MSG_CHECKING([if $CC accepts $NEW_FLAG])
                OLD_CFLAGS="$CFLAGS"
                CFLAGS="$CFLAGS $NEW_FLAG"
		dnl Correctly updated code
		AC_LINK_IFELSE([AC_LANG_SOURCE([int main() { return 0; }])],
		  [
		   AM_CFLAGS="$AM_CFLAGS $NEW_FLAG"
		   AC_MSG_RESULT([yes])
		   ], [
		       AC_MSG_RESULT([no])
		       ])
                CFLAGS="$OLD_CFLAGS"
        done

        AC_ARG_ENABLE([werror],
                AC_HELP_STRING([--enable-werror], [Enable -Werror to abort
                        compilation on all compiler warnings.]),
                [], [enable_werror=no])
        if test "x$enable_werror" = "xyes"; then
                AM_CFLAGS="$AM_CFLAGS -Werror"
        fi
fi

WARNINGCFLAGS="-Wall -W"

AM_CFLAGS="$AM_CFLAGS $WARNINGCFLAGS"
AM_CXXFLAGS="$AM_CFLAGS"

# Add default AM_CFLAGS.
AC_SUBST([AM_CXXFLAGS])

AC_OUTPUT
