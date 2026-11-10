//
// Which order do the lines come out in?  Run it several times.
//
#include <stdio.h>
#include <pthread.h>

void *worker(void *arg) {
    char *name = (char *)arg;
    printf("%s: start\n", name);
    printf("%s: done\n", name);
    return NULL;
}

int main() {
    pthread_t a, b;
    printf("main: before create\n");
    pthread_create(&a, NULL, worker, "A");
    pthread_create(&b, NULL, worker, "B");
    pthread_join(a, NULL);
    printf("main: A joined\n");
    pthread_join(b, NULL);
    printf("main: B joined\n");
    return 0;
}
