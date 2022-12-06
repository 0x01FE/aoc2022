#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int findSmallest(int array[3]) {

    int smallestNumberPosition = 0;
    int smallestNumber = array[0];

    for (int i = 1; i < 3; i++) {

        if (array[i] < smallestNumber) {
            smallestNumber = array[i];
            smallestNumberPosition = i;
        }
    }

    return smallestNumberPosition;
}


int main() {

    FILE  *textfile;
    char *line = malloc(256);

    int topThree[3] = {0,0,0};
    int currentCal;

    currentCal = 0;
    
    textfile = fopen("input.txt","r");
    
    while(fgets(line, 10, textfile)) {

        if (atoi(line) == 0) {

            for (int i=0; i < 3; i++) {

                bool zeroCheck = false;

                if (currentCal > topThree[i]) {
                    int smallestPos = findSmallest(topThree);
                    topThree[smallestPos] = currentCal;
                    break;
                }
            }

            currentCal = 0;
        } else {
            currentCal +=  atoi(line);
        }
    }
    
    int total = 0;
    for (int i=0;i<3;i++) {
        total+=topThree[i];
    }
    printf("Total of the top three elves: %d\n",total);

    fclose(textfile);
    
    return 0;
}
