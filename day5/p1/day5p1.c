#include <stdlib.h>
#include <stdio.h>
#include <string.h>






int main()
{
    char Filename[] = "test.text";

    char *String = malloc(5);

    strcpy(String, "Test");

    size_t StringSize = strlen(String) + 1;
    printf("%d\n", StringSize);


    String = realloc(String, 6);

    printf(strcat(String, "s"));



    free(String);

    return 0;
}