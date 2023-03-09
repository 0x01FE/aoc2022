#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool IntRangeInIntRange(int a, int b, int c, int d)
{
    if (c <= a && d >= b)
        return true;

    else
        return false;
}




int main()
{
    FILE *File;

    File = fopen("input.text", "r");

    char *Line = malloc(256);

    while(fgets(Line, 256, File) != NULL)
    {

    }




    return 0;
}