#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int CountLines(FILE *File)
{
    char *Line = malloc(256);
    int LineCount = 0;

    while (fgets(Line, 256, File) != NULL)
    {
        LineCount++;
    }

    return LineCount;
}


void GetLine(FILE *File, int LineNumber, char* Line)
{
    int CurrentLineNumber = 1;

    while (fgets(Line, sizeof Line, File) != NULL)
    {

        if (CurrentLineNumber == LineNumber)
            break;

        else
            CurrentLineNumber++;

    }

}


int main()
{

    FILE *File;

    int Total = 0;
    int Priority = 0;

    int CurrentLine = 1;
    int CurrentGroup = 1;


    File = fopen("test.txt", "r");
    int LineCount = CountLines(File);

    while (CurrentLine <= LineCount)
    {

        char SharedItem = ' ';

        char *Member1 = malloc(256);
        char *Member2 = malloc(256);
        char *Member3 = malloc(256);

        GetLine(File, CurrentLine, Member1);
        GetLine(File, CurrentLine + 1, Member2);
        GetLine(File, CurrentLine + 2, Member3);


        for (int a = 0; a < strlen(Member1); a++)
        {

            char Item1 = Member1[a];

            // Loop through each member looking for a shared character
            for (int b = 0; b < strlen(Member2); b++)
            {

                char Item2 = Member2[b];

                if (Item1 == Item2)
                {
                    for (int c = 0; c < strlen(Member3); c++)
                    {

                        char Item3 = Member3[c];

                        if ((Item1 == Item3) && (Item2 == Item3))
                        {
                            SharedItem = Item3;
                        }

                    }

                }

                // Don't bother searching through the rest if a shared character is found
                if (SharedItem != ' ')
                    break;
            }

        }

        printf("Shared Item of Group %d was %c\n", CurrentGroup, SharedItem);

        // Convert character to integer value
        int n = (int) SharedItem;

        // A-Z ; - 38 to get values 27-52
        if (n >= 65 && n <= 90)
            Priority = n-38;

        // a-z ; - 96 to get values 1-26
        else if (n >= 97 && n <= 122)
            Priority = n-96;


        Total += Priority;

        // Each group is three lines, so iterate by three.
        CurrentLine += 3;
        CurrentGroup++;

    }

    printf("Total Group Item Priority: %d\n", Total);

    fclose(File);

    return 0;
}