#include <stdlib.h>
#include <stdio.h>


int main()
{
    char ** Test = malloc(100);

    // First row of test equals "Test"
    *(Test) = "Test";

    // Second row of test equals "World"
    *(Test + 1) = "World";

    printf("Using pointer offsets to go through each row\n");
    for (int i = 0; i < 2; i++)
    {
        printf(*(Test + i));
        printf("\n");
    }

    printf("\nUsing pointer offsets in a slightly different way...\n");
    for (int i = 0; i < 2; i++)
    {
        printf(*Test + i);
        printf("\n");
    }

    printf(Test[0]);
}