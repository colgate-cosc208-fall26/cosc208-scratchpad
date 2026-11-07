//
// how many processes?  how many lines of output?
//
#include <stdio.h>
#include <unistd.h>
int main() {
    for (int i = 0; i < 3; i++) {
        fork();
    }
    printf("hello from %d (parent %d)\n", getpid(), getppid());
    return 0;
}
