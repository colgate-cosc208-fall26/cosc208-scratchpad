//
// N threads say hello.  Compile with -pthread.
//   ./hello_threads 4
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hello(void *arg) {
    int id = *(int *)arg;          // cast, then dereference
    printf("hello from thread %d\n", id);
    return NULL;
}

int main(int argc, char **argv) {
    int n = (argc > 1) ? atoi(argv[1]) : 2;
    pthread_t tids[n];
    int ids[n];

    for (int i = 0; i < n; i++) {
        ids[i] = i;                 // each thread gets its OWN int to point at
        pthread_create(&tids[i], NULL, hello, &ids[i]);
    }
    printf("main: all %d threads created\n", n);
    for (int i = 0; i < n; i++) {
        pthread_join(tids[i], NULL);
    }
    printf("main: all threads joined\n");
    return 0;
}
