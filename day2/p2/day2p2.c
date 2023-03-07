#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *textfile;
    char line[6];
    int totalScore = 0;

    textfile = fopen("input.txt", "r");

    while (fgets(line, 6, textfile) != NULL) {
        int score = 0;
        char me = line[2];
        char opp = line[0];
        
        if (me == 'X') { // Lose
            if (opp == 'A') { // O: Rock, Y: Scissors 
                score+=3;
            } else if (opp == 'B') { // O: Paper, Y: Rock
                score+=1; 
            } else if (opp == 'C') { // O: Scissors, Y: Paper
                score+=2;
            }
        } else if (me == 'Y') { // Draw 
            score+=3;
            if (opp == 'A') { // O: Rock, Y: Rock
                score+=1;
            } else if (opp == 'B') { // O: Paper, Y: Paper
                score+=2; 
            } else if (opp == 'C') { // O: Scissors, Y: Scissors
                score+=3;
            }
        } else if (me == 'Z') { // Win
            score+=6;
            if (opp == 'A') { // O: Rock, Y: Paper
                score+=2;
            } else if (opp == 'B') { // O: Paper, Y: Scissors
                score+=3; 
            } else if (opp == 'C') { // O: Scissors, Y: Rock
                score+=1;
            }
        }
        totalScore+=score;
    }
    
    printf("Total score was %d\n",totalScore);
    fclose(textfile);

    return 0;
}   