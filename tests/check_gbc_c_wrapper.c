#include <stdlib.h>
#include <check.h>
    
#include "tests.h"

int main(int ac, char **av)
{

    int num_failed;
    Suite *s;
    SRunner *sr;

    s = gbc_c_wrapper_signal_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_VERBOSE);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return num_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
