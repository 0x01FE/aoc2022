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



int main() {

    FILE *textfile;
    char line[6];
    int totalScore = 0;

    textfile = fopen("input.txt", "r");

    while (fgets(line, 6, textfile) != NULL) {
        int score = 0;
        char me = line[2];
        char opp = line[0];
        printf("%c %c\n",me,opp);
        
        if (me == 'X') {
            score+=1;
            printf("You played Rock! +1\n");
            if (opp == 'C') { //  Scissors (win)
                score+=6;
                printf("You won! +6\n");
            } else if (opp == 'A') {
                score+=3; // Rock (tie)
                printf("Tie! +3\n");
            }
        } else if (me == 'Y') {
            score+=2;
            printf("You played Paper! +2\n");
            if (opp == 'A') { // Rock (win)
                score+=6;
                printf("You won! +6\n");
            } else if (opp == 'B') {
                score+=3; // Paper (tie)
                printf("Tie! +3\n");
            }
        } else if (me == 'Z') {
            score+=3;
            printf("You played Scissors! +3\n");
            if (opp == 'B') { // Paper (win)
                score+=6;
                printf("You won! +6\n");
            } else if (opp == 'C') {
                score+=3; // Scissors (tie)
                printf("Tie! +3\n");
            }
        }
        totalScore+=score;
    }
    
    printf("Total score was %d\n",totalScore);
    fclose(textfile);

    return 0;
}