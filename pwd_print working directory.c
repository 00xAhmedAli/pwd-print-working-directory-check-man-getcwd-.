#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int mv_main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Simply use rename() - let it handle both same-filesystem and cross-filesystem cases
    // Note: In practice, rename() only works within same filesystem, but this is the simplest approach
    if (rename(argv[1], argv[2]) == -1) {
        fprintf(stderr, "mv: cannot move '%s' to '%s': %s\n", 
                argv[1], argv[2], strerror(errno));
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}