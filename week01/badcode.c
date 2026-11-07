#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    char longest_name[32];
    char min_age;

    // command line args alternate between names and ages
    // keep track of longest name, and minimum age, and
    // print them out at the end
    
    if ((argc - 1) % 2 != 0) {
        printf("Error: need an even number of arguments\n");
        return -1;
    }

    for (int i = 1; i < argc; i += 2) {
        if (strlen(argv[i]) > strlen(longest_name)) {
            int j = 0; 
            while (argv[i][j] != '\0') {
                longest_name[j] = argv[i][j];
                j += 1;
            }
        }

        int this_age = atoi(argv[i+1]);
        if (this_age < min_age) {
            min_age = this_age;
        }
    }

    printf("Longest name: %s\n", longest_name);
    printf("Youngest age: %d\n", min_age);
    return 0;
}

