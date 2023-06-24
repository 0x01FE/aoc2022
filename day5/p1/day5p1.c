#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Node{
    char Letter;
    struct Node * Next;
};


int CountLines(char *FileName)
{
    char *Line = malloc(256);
    int LineCount = 0;

    FILE *File;
    File = fopen(FileName, "r");

    while (fgets(Line, 256, File) != NULL)
    {
        LineCount++;
    }

    fclose(File);

    return LineCount;
}


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





    // Parsing the starting positions
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

            if (ContainerLetter == ' ')
                break;

            struct Node * Current = &Stacks[CurrentCollumn];

            while (Current->Next != NULL)
                Current = Current->Next;


            if (Current->Letter == '0')
            {
                Current->Letter = ContainerLetter;
            }
            else if (Current->Letter != ContainerLetter)
            {
                struct Node * TempNode = malloc(sizeof(char) + sizeof(void *));
                TempNode->Letter = ContainerLetter;
                TempNode->Next = NULL;

                Current->Next = TempNode;
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
            printf("%c", p->Letter);
            p = p->Next;
        }
        printf("\n");
    }



    // Parsing the movements
    CurrentLine = CollumnNumberLine + 2; // Line where movements start

    int Lines = CountLines(FileName);

    while (CurrentLine <= Lines)
    {
        GetLine(FileName, CurrentLine, Line);

        int CurrentToken = 0; // Delimiter Token

        // The numbers in the movement line, move x number of crates from a to b
        int Number; // Number of containers to move
        int Src; // Source
        int Dest; // Destination

        char * Token = strtok(Line, " ");

        while (Token != NULL)
        {
            if (CurrentToken == 1)
            {
                printf("Amount is %s\n", Token);
                Number = atoi(Token);
            }
            else if (CurrentToken == 3)
            {
                printf("Source is %s\n", Token);
                Src = atoi(Token) - 1;
            }
            else if (CurrentToken == 5)
            {
                printf("Destination is %s\n", Token);
                Dest = atoi(Token) - 1;
            }


            Token = strtok(NULL, " ");

            CurrentToken++;
        }


        // Containers that are being moved
        struct Node * TempContainers[Number];

        // Take x off of a
        for (int i = 0; i < Number; i++)
        {
            struct Node * Current = &Stacks[Src];

            while (Current->Next != NULL)
            {
                if (Current->Next == NULL)
                {
                    TempContainers[i] = Current->Next;
                    Current->Next = NULL;
                }
                Current = Current->Next;
            }

            printf("%c\n", TempContainers[i]->Letter);

        }

        CurrentLine++;
    }



    return 0;

}