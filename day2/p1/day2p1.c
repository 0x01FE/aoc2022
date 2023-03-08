#include <stdio.h>
#include <stdlib.h>

/*
KEY

A, X R 1
B, Y P 2
C, Z S 3

win 6
lose 0
draw 3

3 6 You: Scissors; Them: Paper (win)
3 3 You: Scissors; Them: Scissors (tie)
2 0 You: Paper; Them: Scissors (lose)
9+6+2
*/



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

        printf("%c %c\n", Me, Opponent);
        
        if (Me == 'X')
        {
            Score += 1;

            printf("You played Rock! +1\n");

            if (Opponent == 'C') //  Scissors (win)
            {
                Score += 6;
                printf("You won! +6\n");
            }
            else if (Opponent == 'A') // Rock (tie)
            {
                Score += 3;
                printf("Tie! +3\n");
            }
        }
        else if (Me == 'Y')
        {
            Score += 2;

            printf("You played Paper! +2\n");

            if (Opponent == 'A') // Rock (win)
            {
                Score += 6;
                printf("You won! +6\n");
            }
            else if (Opponent == 'B') // Paper (tie)
            {
                Score += 3;
                printf("Tie! +3\n");
            }
        }
        else if (Me == 'Z')
        {
            Score += 3;

            printf("You played Scissors! +3\n");

            if (Opponent == 'B') // Paper (win)
            {
                Score += 6;
                printf("You won! +6\n");
            }
            else if (Opponent == 'C') // Scissors (tie)
            {
                Score += 3;
                printf("Tie! +3\n");
            }
        }
        TotalScore += Score;
    }
    
    printf("Total score was %d\n",TotalScore);

    fclose(File);

    return 0;
}