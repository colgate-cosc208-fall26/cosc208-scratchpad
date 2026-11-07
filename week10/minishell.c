//
// ~30-line shell.  Project 4 is a bigger version of this.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXARGS 32

int main() {
    char line[1024];
    while (1) {
        printf("mini> ");
        fflush(stdout);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;                               // EOF (Ctrl-D)
        }
        char *args[MAXARGS];
        int n = 0;
        for (char *tok = strtok(line, " \t\n"); tok && n < MAXARGS - 1;
             tok = strtok(NULL, " \t\n")) {
            args[n++] = tok;
        }
        args[n] = NULL;
        if (n == 0) continue;
        if (strcmp(args[0], "exit") == 0) break;

        pid_t rv = fork();
        if (rv == 0) {                           // child
            execvp(args[0], args);
            perror(args[0]);                     // only if exec fails
            exit(127);
        }
        int status;                              // parent
        waitpid(rv, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            printf("[%s exited with status %d]\n", args[0], WEXITSTATUS(status));
        }
    }
    return 0;
}
