//
// What does count++ compile to?    gcc -O0 -S incr.c  (look at incr.s)
//
long count = 0;

void increment(void) {
    count++;
}
