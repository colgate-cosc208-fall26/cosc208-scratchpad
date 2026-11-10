//
// count_race.c, fixed: the read-add-write is a critical section,
// so wrap it in a mutex.
//   ./count_mutex 4 1000000     ->  expected 4000000, got 4000000
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long count = 0;
pthread_mutex_t count_lock;     // one lock, shared by every thread

void *increment(void *arg) {
    long loops = *(long *)arg;
    for (long i = 0; i < loops; i++) {
        pthread_mutex_lock(&count_lock);
        count++;                // only one thread at a time in here
        pthread_mutex_unlock(&count_lock);
    }
    return NULL;
}

int main(int argc, char **argv) {
    int n = (argc > 1) ? atoi(argv[1]) : 2;
    long loops = (argc > 2) ? atol(argv[2]) : 1000000;
    pthread_mutex_init(&count_lock, NULL);
    pthread_t tids[n];
    for (int i = 0; i < n; i++) {
        pthread_create(&tids[i], NULL, increment, &loops);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(tids[i], NULL);
    }
    printf("expected %ld, got %ld\n", (long)n * loops, count);
    pthread_mutex_destroy(&count_lock);
    return 0;
}
