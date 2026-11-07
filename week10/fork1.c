//
// one call, two returns
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    printf("before fork: pid %d\n", getpid());
    pid_t rv = fork();
    printf("after fork: pid %d, parent %d, fork returned %d\n",
           getpid(), getppid(), rv);
    if (rv > 0) {
        wait(NULL);  // parent: wait for child (Thursday's topic)
    }
    return 0;
}
