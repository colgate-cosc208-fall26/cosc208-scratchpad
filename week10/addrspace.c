//
// separate address spaces.
//
// The child changes a global, a heap value, and a local
// Same virtual addresses in both processes but different contents
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int counter = 100;              // data segment

int main() {
    int *heapval = malloc(sizeof(int));   // heap
    *heapval = 200;
    int local = 300;                      // stack

    pid_t rv = fork();
    if (rv == 0) {
        counter += 1;
        *heapval += 1;
        local += 1;
        printf("child  %d: counter=%d @%p  heap=%d @%p  local=%d @%p\n",
               getpid(), counter, (void*)&counter, *heapval, (void*)heapval,
               local, (void*)&local);
    } else {
        wait(NULL);   // let the child finish first
        printf("parent %d: counter=%d @%p  heap=%d @%p  local=%d @%p\n",
               getpid(), counter, (void*)&counter, *heapval, (void*)heapval,
               local, (void*)&local);
    }
    free(heapval);
    return 0;
}
