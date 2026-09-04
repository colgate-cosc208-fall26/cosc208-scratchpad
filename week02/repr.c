#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Gimme a value\n");
        return -1;
    }
    int value = atoi(argv[1]);
    printf("%d is 0b%b in binary\n", value, value);
    printf("%d is 0x%x in hex\n", value, value);
    return 0;
}
