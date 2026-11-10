//
// What NOT to do: return the address of a local variable from a thread.
// The thread's stack is gone by the time main looks at it.
//
#include <stdio.h>
#include <pthread.h>

void *square(void *arg) {
    int n = *(int *)arg;
    int result = n * n;        // lives on THIS thread's stack
    return &result;            // dangling as soon as we return (gcc warns)
}

int main() {
    int n = 7;
    pthread_t t;
    pthread_create(&t, NULL, square, &n);
    int *p = NULL;
    pthread_join(t, (void **)&p);
    printf("7 squared is %d\n", *p);   // garbage, crash, or 49 if you're unlucky
    return 0;
}
