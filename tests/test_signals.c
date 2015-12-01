#include <check.h>
#include <sys/mman.h>
#include <stdio.h>  
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "gbc_c_wrapper.h"
#include "tests.h"

START_TEST (test_signal_sigbus)
{
    int fd;
    char *addr;

    newCExceptionHandlerSimple();

    fd = mkostemp("test_gbc", O_CLOEXEC);
    addr = mmap(NULL, 1, PROT_READ, MAP_PRIVATE, fd, 0);
    ftruncate(fd, 0);
    printf("%x\n", addr[0x4]);
}
END_TEST

Suite * gbc_c_wrapper_signal_suite(void)
{
    Suite *s;
    TCase *tc_signal;

    s = suite_create("gbc_c_wrapper");

    tc_signal = tcase_create("signal_handling");

    tcase_add_test(tc_signal , test_signal_sigbus);
    suite_add_tcase(s, tc_signal);

    return s;
}


