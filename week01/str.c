#include <stdio.h>
#include <string.h>

int main() {
    char s[] = {'1', '2', '3'};
    char t[] = "123";

    printf("%ld\n", strlen(s));  // 1
    printf("%ld\n", strlen(t));  // 2
    printf("%c\n", t[3]);       // 3
    printf("%d\n", s[0] - '0'); // 4
    return 0;
}
