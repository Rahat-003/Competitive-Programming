#include <string.h>
#include <stdio.h>


void printIntAsChar(char *c) {
    printf("%p: c[0] = %x\n", (c+0), c[0] & 0xff);
    printf("%p: c[1] = %x\n", (c+1), c[1] & 0xff);
    printf("%p: c[2] = %x\n", (c+2), c[2] & 0xff);
    printf("%p: c[3] = %x\n", (c+3), c[3] & 0xff);
}

int main() {
    int x = 0;

    char *c = &x;
    memset(c, 0xff, 4);
    printf("x = %zu\n", x);

    printIntAsChar(c);
}
