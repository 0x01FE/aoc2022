#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct File {
    char * Name;
    int size;
};

struct Dir {
    char * Name;
    int size;
    struct Dir * Parent;
    int ChildrenAmount;
    struct Dir ** Children;
    int FileCount;
    struct File ** Files;
};

struct Dir * FindDir(struct Dir * CurrentDir, char * target_name)
{
    for (int index = 0; index < CurrentDir->ChildrenAmount; index++)
    {
        char * current_child_name = CurrentDir->Children[index]->Name;
        if (strcmp(current_child_name, target_name) == 0)
            return CurrentDir->Children[index];
    }
    return NULL;
}

char * RemoveLastChar(char * Str)
{
    size_t length = strlen(Str);
    char * NewString = malloc(length * sizeof(char));
    for (int index = 0; index < length - 1; index++)
        NewString[index] = Str[index];
    return NewString;
}

int CountLines(char * FileName)
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

void GetLine(char * FileName, int LineNumber, char * Line)
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
    printf("Size: %d, ", Current->size);

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
    Root.size = 0;
    Root.Parent = NULL;
    Root.ChildrenAmount = 0;
    Root.FileCount = 0;
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
                if (strcmp(Command, "cd") == 0)
                {
                    char * target_dir_name = strtok(NULL, " ");
                    CurrentDirectory = FindDir(CurrentDirectory, target_dir_name);
                    Command = strtok(NULL, " ");
                }
                else if (strcmp(Command, "ls\n") == 0)
                {
                    // Find how many items we need to put into an array
                    int Directories = 0;
                    int LineOffset = 1;

                    do
                    {
                        printf("get line %d\n", CurrentLine+LineOffset);
                        GetLine(FileName, CurrentLine + LineOffset, Line);

                        if (Line[0] == '$')
                            break;

                        char * FirstWord = strtok(Line, " ");

                        if (strcmp(FirstWord, "dir") == 0)
                            Directories++;

                        else if (isdigit(Line[0]))
                        {
                            int add = atoi(FirstWord);
                            printf("Adding size %d to %s\n", add, CurrentDirectory->Name);
                            CurrentDirectory->size += add;
                            printf("CurrentDirectory Size is %d\n", CurrentDirectory->size);
                        }

                        LineOffset++;
                    }
                    while (1);

                    printf("%d Directories found\n", Directories);

                    // CurrentLine += LineOffset;

                    printf("Getting directories...\n");
                    if (Directories > 0)
                    {
                        LineOffset = 1;

                        struct Dir ** TempChildren = malloc(sizeof(struct Dir) * Directories);

                        for (int i = 0; i < Directories; i++)
                        {
                            while (1)
                            {
                                GetLine(FileName, CurrentLine + LineOffset, Line);
                                printf("get line %d\n", CurrentLine + LineOffset);

                                char * FirstWord = malloc(256);
                                FirstWord = strtok(Line, " ");

                                LineOffset++;
                                if (strcmp(FirstWord, "dir") == 0)
                                {
                                    FirstWord = strtok(NULL, " ");

                                    struct Dir * TempDirectory = malloc(sizeof(struct Dir));

                                    TempDirectory->Name = RemoveLastChar(FirstWord);
                                    TempDirectory->Parent = CurrentDirectory;

                                    TempChildren[i] = TempDirectory;
                                    break;
                                }
                            }
                        }

                        CurrentDirectory->Children = TempChildren;
                        CurrentDirectory->ChildrenAmount = Directories;
                    }
                }

                Command = strtok(NULL, " ");
            }
        }

        if (CurrentLine == 13)
            break;

        CurrentLine++;
    }

    PrintDir(&Root);
}