//
// exec replaces the program, keeps the process
//
#include <stdio.h>
#include <unistd.h>
int main() {
    printf("I am process %d, about to become 'echo'\n", getpid());
    fflush(stdout);
    char *args[] = { "echo", "hello from echo", NULL };
    execvp(args[0], args);
    // only reached if execvp fails
    perror("execvp");
    return 1;
}
