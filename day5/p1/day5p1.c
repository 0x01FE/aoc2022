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

        printf("%s", Line);

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
    printf("Collumns : %d\n\n", Collumns);

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
        int NodeC = 1;
        CurrentLine = CollumnNumberLine-1;
        Place = (CurrentCollumn * 4) + 1;
        printf("\nGoing to collumn %d\n", CurrentCollumn);
        struct Node * Current = &Stacks[CurrentCollumn];

        while (CurrentLine > 0)
        {
            GetLine(FileName, CurrentLine, Line);

            ContainerLetter = Line[Place];

            printf("p->Letter is %c!\n", Current->Letter);
            while (Current != NULL)
            {
                if (ContainerLetter == ' ')
                    break;

                if (Current->Letter == '0')
                {
                    printf("Setting stack %d node %d from %c -> %c\n\n", CurrentCollumn, NodeC, Current->Letter, ContainerLetter);
                    Current->Letter = ContainerLetter;
                }
                else if (Current->Letter != ContainerLetter)
                {
                    struct Node * TempNode = malloc(sizeof(char) + sizeof(void *));
                    printf("Setting stack %d node %d from NULL -> %c\n\n", CurrentCollumn, NodeC, ContainerLetter);
                    TempNode->Letter = ContainerLetter;
                    TempNode->Next = NULL;

                    printf("p is %p\n", Current);
                    Current->Next = TempNode;
                    printf("Next is %p\n", Current->Next);
                }

                Current = Current->Next;
                printf("p is %p\n", Current);

            }

            NodeC++;
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