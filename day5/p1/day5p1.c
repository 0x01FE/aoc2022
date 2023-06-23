#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Node{
    char Letter;
    struct Node * Next;
};


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
    struct Node Stacks[Collumns];

    for (int i = 0; i < Collumns; i++)
    {
        Stacks[i].Letter = '0';
        Stacks[i].Next = NULL;
    }

    int CurrentCollumn = 0; // Actual Collumn Number is this +1
    int Place;
    // char * CollumnContent;
    char ContainerLetter;

    while (CurrentCollumn < Collumns)
    {

        CurrentLine = CollumnNumberLine-1;
        Place = (CurrentCollumn * 4) + 1;
        while (CurrentLine > 0)
        {
            GetLine(FileName, CurrentLine, Line);

            ContainerLetter = Line[Place];

            struct Node * p = &Stacks[CurrentCollumn];

            while (p != NULL)
            {
                if (p->Letter == '0')
                {
                    printf("Setting stack %d node to %c", CurrentCollumn, ContainerLetter);
                    p->Letter = ContainerLetter;
                }
                else
                {
                    struct Node TempNode;
                    TempNode.Letter = ContainerLetter;

                    p->Next = &TempNode;
                }

                p = p->Next;
            }

            CurrentLine--;
        }

        CurrentCollumn++;
    }


    for (int i = 0; i < Collumns; i++)
    {
        printf("Letters for Stack %d:\n", i);
        struct Node * p = &Stacks[i];

        while (p != NULL)
        {
            printf("%c\n", p->Letter);
            p = p->Next;
        }
    }








    return 0;

}