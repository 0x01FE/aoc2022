#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


struct Dir {
    char * Name;
    int Size;
    struct Dir * Parent;
    int ChildrenAmount;
    struct Dir ** Children;
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



void PrintDir(struct Dir * Current)
{
    printf("Name: %s, ", Current->Name);
    printf("Children: %d, ", Current->ChildrenAmount);

    if (Current->Parent)
        printf("Parent: %s",  Current->Parent->Name);

    printf("\n");

    for (int i = 0; i < Current->ChildrenAmount; i++)
    {
        PrintDir(Current->Children[i]);
    }
}



int main()
{
    struct Dir Root;
    Root.Name = "Root";
    Root.Parent = NULL;
    struct Dir * CurrentDirectory = &Root;

    char FileName[] = "test.text";
    int LineCount = CountLines(FileName);
    int CurrentLine = 2; // Skipping line one
    char * Line = malloc(256);
    char * Command = malloc(256);

    while (CurrentLine <= LineCount)
    {
        GetLine(FileName, CurrentLine, Line);

        if (Line[0] == '$')
        {
            Command = strtok(Line, " ");
            Command = strtok(NULL, " ");

            while (Command != NULL)
            {
                if (Command == "cd")
                {

                }
                else if (strcmp(Command, "ls\r\n") == 0)
                {
                    // Find how many items we need to put into an array
                    int Directories = 0;
                    int LineOffset = 1;

                    do
                    {
                        if (Line[0] == '$')
                            break;

                        printf("get line %d\n", CurrentLine+LineOffset);
                        GetLine(FileName, CurrentLine + LineOffset, Line);

                        char * FirstWord = strtok(Line, " ");

                        if (strcmp(FirstWord, "dir") == 0)
                            Directories++;

                        else if (isdigit(Line[0]))
                            CurrentDirectory->Size += atoi(FirstWord);

                        LineOffset++;
                    }
                    while (1);

                    printf("%d Directories found\n", Directories);

                    CurrentLine += LineOffset;

                    if (Directories > 0)
                    {
                        LineOffset = 1;

                        struct Dir ** TempChildren = malloc(sizeof(struct Dir) * Directories);

                        for (int i = 0; i < Directories; i++)
                        {
                            while (1)
                            {
                                GetLine(FileName, CurrentLine + LineOffset, Line);

                                char * FirstWord = malloc(256);
                                FirstWord = strtok(Line, " ");

                                if (strcmp(FirstWord, "dir") == 0)
                                {
                                    FirstWord = strtok(NULL, " ");

                                    struct Dir * TempDirectory = malloc(sizeof(struct Dir));

                                    TempDirectory->Name = FirstWord;
                                    TempDirectory->Parent = CurrentDirectory;

                                    TempChildren[i] = TempDirectory;
                                    break;
                                }
                                else
                                    LineOffset++;
                            }
                        }

                        CurrentDirectory->Children = TempChildren;
                        CurrentDirectory->ChildrenAmount = Directories;
                    }
                }

                Command = strtok(NULL, " ");
            }
        }

        if (CurrentLine == 6)
            break;

        CurrentLine++;
    }

    PrintDir(CurrentDirectory);
}