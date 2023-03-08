#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *File;
    char Line[6];

    int TotalScore = 0;

    File = fopen("input.txt", "r");

    while (fgets(Line, 6, File) != NULL)
    {

        int Score = 0;

        char Me = Line[2];
        char Opponent = Line[0];
        
        if (Me == 'X')  // Lose
        {
            // O: Rock, Y: Scissors
            if (Opponent == 'A')
                Score += 3;

            // O: Paper, Y: Rock
            else if (Opponent == 'B')
                Score += 1;

            // O: Scissors, Y: Paper
            else if (Opponent == 'C')
                Score += 2;

        }
        else if (Me == 'Y') // Draw
        {

            Score += 3;

            // O: Rock, Y: Rock
            if (Opponent == 'A')
                Score += 1;

            // O: Paper, Y: Paper
            else if (Opponent == 'B')
                Score += 2;

            // O: Scissors, Y: Scissors
            else if (Opponent == 'C')
                Score += 3;

        }
        else if (Me == 'Z') // Win
        {

            Score+=6;

            // O: Rock, Y: Paper
            if (Opponent == 'A')
                Score += 2;

            // O: Paper, Y: Scissors
            else if (Opponent == 'B')
                Score += 3;

            // O: Scissors, Y: Rock
            else if (Opponent == 'C')
                Score += 1;

        }

        TotalScore += Score;
    }
    

    printf("Total score was %d\n",TotalScore);

    fclose(File);

    return 0;
}