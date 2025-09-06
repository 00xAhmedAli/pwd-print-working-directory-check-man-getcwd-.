#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[1024];
    
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("Current working directory: %s\n", buf);
    } else {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}