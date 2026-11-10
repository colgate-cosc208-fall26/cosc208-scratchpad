//
// Passing several arguments to a thread (a struct) and getting a result
// back (a malloc'd pointer handed to pthread_join).
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct count_args {
    char *str;
    char ch;
};

void *count_char(void *arg) {
    struct count_args *a = (struct count_args *)arg;   // cast once
    int *result = malloc(sizeof(int));                 // lives past this function
    *result = 0;
    for (int i = 0; a->str[i] != '\0'; i++) {
        if (a->str[i] == a->ch) {
            (*result)++;
        }
    }
    return result;                                     // becomes join's *retval
}

int main(int argc, char **argv) {
    char *str = (argc > 1) ? argv[1] : "mississippi";
    char *letters = "ips";
    int n = strlen(letters);

    struct count_args args[n];
    pthread_t tids[n];
    for (int i = 0; i < n; i++) {
        args[i].str = str;
        args[i].ch = letters[i];
        pthread_create(&tids[i], NULL, count_char, &args[i]);
    }
    for (int i = 0; i < n; i++) {
        int *count = NULL;
        pthread_join(tids[i], (void **)&count);
        printf("'%c' appears %d times in %s\n", letters[i], *count, str);
        free(count);
    }
    return 0;
}
