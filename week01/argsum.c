#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("error: need at least 3 args\n");
        return -1;
    }
    int sum = 0;
    for (int i = 1; i < argc; i++) {
       sum += atoi(argv[i]);        
    }
    printf("sum: %d\n", sum);
    return 0;
}

