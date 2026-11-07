//
// no wait() -> no guarantee about order.
//
#include <stdio.h>
#include <unistd.h>
int main() {
    printf("Begin\n");
    pid_t rv = fork();
    if (rv > 0) {
        printf("Egg\n");
    } else {
        printf("Chicken\n");
    }
    return 0;
}
