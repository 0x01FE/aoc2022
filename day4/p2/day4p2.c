#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool Overlap(int * Ranges[4])
{

    for (int * x = Ranges[0]; x <= Ranges[1]; x++)
    {
        for (int * y = Ranges[2]; y <= Ranges[3]; y++)
        {
            if (x == y)
            {
                return true;
            }
        }
    }

    return false;

}


int main()
{

    FILE * File;

    File = fopen("input.text", "r");


    char * Line = malloc(256);

    int Total = 0;


    char ** Elves;

    Elves = malloc(2);

    int * ElfRanges[4];
    //exit(1);
    while(fgets(Line, 256, File) != NULL)
    {

        for (int i = 0; i < 4; i++)
            ElfRanges[i] = NULL;


        // Splits the line by the comma in the middle of the line to get each elf's range
        Elves[0] = strtok(Line, ",");
        Elves[1] = strtok(NULL, ",");


        // Loop through both elves
        for (int a = 0; a < 2; a++)
        {

            printf(Elves[a]);
            printf(" ");

            char *Task = strtok(Elves[a], "-");

            while (Task != NULL)
            {

                for (int i = 0; i < 4; i++)
                {
                    if (ElfRanges[i] == NULL)
                    {
                        ElfRanges[i] = (int *) strtol(Task, NULL, 10);
                        break;
                    }
                }

                Task = strtok(NULL, "-");

            }

        }

        printf("Elf Pair Ranges: ");
        for (int i = 0; i < 4; i++)
            printf("%d ", ElfRanges[i]);

        printf("\n\n");


        if (Overlap(ElfRanges))
            Total++;

    }

    printf("Total Overlaps: %d\n", Total);

    fclose(File);
}