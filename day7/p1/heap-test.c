#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int main() {

    int ** p = malloc(2);

    int * a = 1;
    int * b = 2;

    p[0] = a;
    p[1] = b;

    printf("Size: %d\n", malloc_usable_size(p));

    return 1;
}