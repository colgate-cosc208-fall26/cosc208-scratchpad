//
// look at the processes with ps while they're alive.
//
//   ./sleepy_child &     then      ps -o pid,ppid,stat,cmd
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    printf("parent %d starting\n", getpid());
    pid_t rv = fork();
    if (rv < 0) {
        perror("fork");
        return 1;
    } else if (rv == 0) {
        printf("child %d sleeping\n", getpid());
        sleep(30);
    } else {
        printf("parent %d: my child is %d\n", getpid(), rv);
        wait(NULL);
        printf("parent: child is done\n");
    }
    return 0;
}
