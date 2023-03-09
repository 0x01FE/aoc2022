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

    File = fopen("test.text", "r");

    char *Line = malloc(256);

    int Total = 0;


    while(fgets(Line, 256, File) != NULL)
    {
        int ElfRanges[4] = {0, 0, 0, 0};

        char *Elves[2] = malloc(256);

        // Splits the line by the comma in the middle of the line to get each elf's range
        char *Elf = strtok(Line, ",");
        Elves[0] = Elf;

        int i = 1;
        while (Elf != NULL)
        {
            Elves[i] = strok(NULL, ",");
            i++;
        }

        // Loop through both elves
        for (int a = 0; a < 2; a++)
        {

            printf(Elves[a]);
            printf("\n");

            char *Task = strtok(Elves[a], "-");

            while (Task != NULL)
            {

                for (int i = 0; i < (sizeof ElfRanges / sizeof (ElfRanges[0])); i++)
                {
                    if (ElfRanges[i] == 0)
                    {
                        ElfRanges[i] = (int) strtol(Task, NULL, 10);
                        break;
                    }
                }

                Task = strtok(NULL, "-");

            }

        }

        printf("Elf Pair Ranges: ");
        for (int i = 0; i < (sizeof ElfRanges / sizeof (ElfRanges[0])); i++)
        {
            printf("%d ", ElfRanges[i]);
        }

        printf("\n");
    }


    fclose(File);

    return 0;
}