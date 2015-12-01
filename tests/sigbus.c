#include <sys/mman.h>
#include <stdio.h>  
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <gbc_c_wrapper.h>

int main(int argc, char **argv)  
{  
    int fd;
    char *addr;

    if (argc != 2) {
        fprintf(stderr, "sigbus <emptyfile>");
        return EXIT_FAILURE;
    }
    newCExceptionHandlerSimple();

    fd = open(argv[1], O_RDONLY);
    addr = mmap(NULL, 1, PROT_READ, MAP_PRIVATE, fd, 0);
    ftruncate(fd, 0);
    fd = getchar();
    printf("%x\n", addr[0x4]);
    //should not happen!!!
    return EXIT_SUCCESS;  
}  
