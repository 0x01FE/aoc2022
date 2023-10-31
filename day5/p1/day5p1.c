#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Node {
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

    char FileName[] = "input.text";

    int CollumnNumberLine;

    int Collumns;

    int CurrentLine = 1;
    char * Line = malloc(256);

    do
    {

        GetLine(FileName, CurrentLine, Line);


        if (isdigit(Line[1]))
        {
            CollumnNumberLine = CurrentLine;
            break;
        }
        else
            CurrentLine++;

    }
    while (Line != NULL);



    Collumns = strlen(Line) / 4;






    // Parsing the starting positions
    struct Node * Stacks[Collumns];

    for (int i = 0; i < Collumns; i++)
    {
        struct Node * TempNode = malloc(sizeof(char) + sizeof(void *));
        TempNode->Letter = '0';
        TempNode->Next = NULL;

        Stacks[i] = TempNode;
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

            struct Node * Current = Stacks[CurrentCollumn];

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



    // Parsing the movements
    CurrentLine = CollumnNumberLine + 2; // Line where movements start

    int Lines = CountLines(FileName);

    // Move the crates
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
                Number = atoi(Token);

            else if (CurrentToken == 3)
                Src = atoi(Token) - 1;

            else if (CurrentToken == 5)
                Dest = atoi(Token) - 1;

            Token = strtok(NULL, " ");

            CurrentToken++;
        }

        // Containers that are being moved
        char TempContainers[Number];

        // Take x off of a and put into letters TempContainers
        for (int i = 0; i < Number; i++)
        {
            struct Node * Current = Stacks[Src];

            while (Current != NULL)
            {
                if (Current->Next == NULL)
                {
                    TempContainers[i] = Current->Letter;
                    Stacks[Src] = NULL;
                    break;
                }
                else if (Current->Next->Next == NULL)
                {
                    TempContainers[i] = Current->Next->Letter;
                    Current->Next = NULL;
                    break;
                }

                Current = Current->Next;
            }

        }

        // Take the letters from TempContainers and put them in b
        for (int i = 0; i < Number; i++)
        {
            struct Node * Current = Stacks[Dest];

            while (1)
            {
                if (Current == NULL)
                {
                    struct Node * TempNode = malloc(sizeof(char) + sizeof(void *));
                    TempNode->Letter = TempContainers[i];
                    TempNode->Next = NULL;

                    Stacks[Dest] = TempNode;
                    break;
                }
                else if (Current->Next == NULL)
                {
                    struct Node * TempNode = malloc(sizeof(char) + sizeof(void *));
                    TempNode->Letter = TempContainers[i];
                    TempNode->Next = NULL;

                    Current->Next = TempNode;
                    break;
                }

                Current = Current->Next;
            }
        }

        CurrentLine++;
    }


    printf("\nTop containers of each stack: ");

    for (int i = 0; i < Collumns; i++)
    {
        struct Node * Current = Stacks[i];

        while (Current->Next != NULL)
        {
            Current = Current->Next;
        }

        printf("%c", Current->Letter);
    }
    printf("\n");


    // Should print out the stacks with the top character CMZ

    return 0;

}