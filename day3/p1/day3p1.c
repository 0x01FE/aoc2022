#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
A-Z : 65-90 ; - 38
a-z : 97-122 ; - 96
*/

void PrintLine(char Line[], int Start, int End)
{
    for (int i = Start; i < End; i++) {
        printf("%c", Line[i]);
    }
    printf("\n");
}

int main()
{

    FILE *File;
    char *Line = malloc(256);
    int Total = 0;
    int Priority = 0;

    File = fopen("input.txt", "r");

    while (fgets(Line, 256, File) != NULL)
    {

        int Size = strlen(Line);
        int Compartment1End = Size/2; // compartment 1 end

        char Shared = ' ';


        PrintLine(Line, 0, Compartment1End);
        PrintLine(Line, Compartment1End, Size);


        for (int i = 0; i < Compartment1End; i++)
        {
            char Current = Line[i];

            for (int y = Compartment1End; y < Size; y++)
            {
                if (Current == Line[y])
                {
                    Shared = Line[y];
                    break;
                }
            }

            if (Shared != ' ')
            {
                break;
            }
        }


        printf("Shared Item: %c\n", Shared);
        printf("\n");


        int n = (int) Shared;

        if (n >= 65 && n <= 90)
            Priority = n-38;

        else if (n >= 97 && n <= 122)
            Priority = n-96;


        Total += Priority;

    }

    printf("Total priority is %d\n", Total);

    fclose(File);

    return 0;
}