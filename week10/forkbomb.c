#include <stdio.h>
#include <unistd.h>

int main() {
    unsigned long long i = 0;
    while (1) {
        i++;
        fork();
        // printf("%lld\n", i);
    }
    return 0;
}
