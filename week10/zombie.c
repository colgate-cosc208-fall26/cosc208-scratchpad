//
// a child that exits before its parent waits.
//   ./zombie &    then    ps -o pid,ppid,stat,cmd     (look for Z / <defunct>)
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t rv = fork();
    if (rv == 0) {
        printf("child %d: done already!\n", getpid());
        exit(0);
    }
    printf("parent %d: not waiting for %d yet...\n", getpid(), rv);
    sleep(30);
    wait(NULL);
    printf("parent: finally reaped the child\n");
    return 0;
}
