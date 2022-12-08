#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main() {
    char *token = malloc(20);
    char string[11] = "Hello World";

    token = strtok(string, " ");

    printf("First token: %s\n", token);

    token = strtok(NULL, " ");

    printf("Second token: %.*s\n", 5, token);

    return 0;
}