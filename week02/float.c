#include <stdio.h>

int main() {
    float a, b, c;

    a = 1.345f;
    b = 1.123f;
    c = a + b;
    if (c == 2.468) {
        printf("They are equal.\n");
    } else {
       printf("They are not equal! The value of c is %13.10f or %f",c,c);
    }
    return 0;
}
