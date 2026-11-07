//
// wait() blocks AND collects the child's exit status
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char **argv) {
    int code = (argc > 1) ? atoi(argv[1]) : 0;
    pid_t rv = fork();
    if (rv == 0) {
        printf("child %d: exiting with %d\n", getpid(), code);
        exit(code);
    }
    int status = 0;
    pid_t done = waitpid(rv, &status, 0);
    if (WIFEXITED(status)) {
        printf("parent: child %d exited with status %d\n",
               done, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("parent: child %d killed by signal %d\n",
               done, WTERMSIG(status));
    }
    return 0;
}
