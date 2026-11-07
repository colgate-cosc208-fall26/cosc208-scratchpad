//
// the fork / exec / wait pattern (what a shell does)
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    char *args[] = { "ls", "-l", NULL };
    pid_t rv = fork();
    if (rv == 0) {
        execvp(args[0], args);
        perror("execvp");      // only on failure
        exit(1);
    }
    int status;
    waitpid(rv, &status, 0);
    printf("ls (pid %d) finished with status %d\n", rv, WEXITSTATUS(status));
    return 0;
}
