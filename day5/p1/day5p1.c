#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>



void GetLine(char *FileName, int LineNumber, char* Line)
{

    int CurrentLineNumber = 1;

    FILE *File;
    File = fopen(FileName, "r");

    while (fgets(Line, 256, File) != NULL)
    {

        if (CurrentLineNumber == LineNumber)
            break;

        else
            CurrentLineNumber++;

    }

    fclose(File);

}




int main()
{

    char FileName[] = "test.text";

    int CollumnNumberLine;

    int Collumns;

    int CurrentLine = 1;
    char * Line = malloc(256);

    do
    {

        GetLine(FileName, CurrentLine, Line);

        printf(Line);

        if (isdigit(Line[1]))
        {
            CollumnNumberLine = CurrentLine;
            break;
        }
        else
            CurrentLine++;

    }
    while (Line != NULL);

    printf("Collumn Number Line : %d\n", CollumnNumberLine);

    Collumns = strlen(Line) / 4;
    printf("Collumns : %d\n", Collumns);

    /*
        Collumn Number Line - 1 should match the number of lines it took to get to
        the bottom of the drawing which we can then infer the max number of items in one stack with.
    */
    char * Stacks[Collumns][CollumnNumberLine - 1];












    return 0;

}