//
// Two or more threads increment one shared counter.  Lost updates.
//   ./count_race 4 1000000     ->  expected 4000000, actual: less
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long count = 0;                 // shared: one copy, in the data segment

void *increment(void *arg) {
    long loops = *(long *)arg;
    for (long i = 0; i < loops; i++) {
        count++;                // read, add, write: three instructions
    }
    return NULL;
}

int main(int argc, char **argv) {
    int n = (argc > 1) ? atoi(argv[1]) : 2;
    long loops = (argc > 2) ? atol(argv[2]) : 1000000;
    pthread_t tids[n];
    for (int i = 0; i < n; i++) {
        pthread_create(&tids[i], NULL, increment, &loops);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(tids[i], NULL);
    }
    printf("expected %ld, got %ld\n", (long)n * loops, count);
    return 0;
}
