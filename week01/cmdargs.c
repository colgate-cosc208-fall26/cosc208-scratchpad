#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("The executable file is: %s\n", argv[0]);
    printf("There are %d additional arguments\n", argc-1);
    for (int i = 1; i < argc; i++) {
        printf("%d) %s\n", i, argv[i]);
    }
}

