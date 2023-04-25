#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>



char * GetLine(char *FileName, int LineNumber)
{
    int CurrentLineNumber = 1;

    FILE *File;
    File = fopen(FileName, "r");
    char * Line = malloc(256);

    while (fgets(Line, 256, File) != NULL)
    {

        if (CurrentLineNumber == LineNumber)
            return Line;

        else
            CurrentLineNumber++;

    }

    fclose(File);

}

int main()
{

    char Filename[] = "test.text";

    char * Line = malloc(256);
    int EndOfDrawing;

    int CurrentLine = 1;
    while (true)
    {

        Line = GetLine(Filename, CurrentLine);

        if (isdigit(Line[2]))
        {
            EndOfDrawing = CurrentLine;
            break;
        }
        else
            CurrentLine++;

    }

    return 0;

}