#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int MARKER_LENGTH = 14;
int MAX_LENGTH = 4095;

int CountLines(char * FileName)
{
    char *Line = malloc(MAX_LENGTH);
    int LineCount = 0;

    FILE *File;
    File = fopen(FileName, "r");

    while (fgets(Line, MAX_LENGTH, File) != NULL)
    {
        LineCount++;
    }

    fclose(File);

    return LineCount;
}



void GetLine(char * FileName, int LineNumber, char * Line)
{

    int CurrentLineNumber = 1;

    FILE * File;
    File = fopen(FileName, "r");

    while (fgets(Line, MAX_LENGTH, File) != NULL)
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
    char Marker[MARKER_LENGTH];

    char FileName[] = "input.text";
    int LineCount = CountLines(FileName);
    int CurrentLine = 1;
    char * Line = malloc(MAX_LENGTH);

    do
    {
        // Clear Marker for new line
        for (int i = 0; i < MARKER_LENGTH; i++)
            Marker[i] = '\0';

        GetLine(FileName, CurrentLine, Line);

        for (int i = 0; i < strlen(Line); i++)
        {
            if (i < MARKER_LENGTH)
            {
                if (!Marker[i])
                {
                    Marker[i] = Line[i];
                }
            }
            else
            {
                bool Repeat = false;

                for (int a = 0; a < MARKER_LENGTH; a++)
                {
                    for (int b = 0; b < MARKER_LENGTH; b++)
                    {
                        if (Marker[a] == Marker[b] && a != b)
                        {
                            Repeat = true;
                            break;
                        }
                    }
                }

                if (!Repeat)
                {
                    printf("Marker starts at character %d\n", i);
                    for (int x = 0; x < MARKER_LENGTH; x++)
                        printf("%c", Marker[x]);
                    printf("\n");
                    break;
                }
                else
                {
                    // Shift everything in Marker to the left by one
                    Marker[0] = '\0';

                    for (int x = 1; x < MARKER_LENGTH; x++)
                        Marker[x-1] = Marker[x];

                    Marker[MARKER_LENGTH-1] = Line[i];
                }
            }
        }

        CurrentLine++;

    }
    while (CurrentLine <= LineCount);

    return 1;
}