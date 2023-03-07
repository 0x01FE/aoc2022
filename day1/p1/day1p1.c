#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE  *textfile;
    char *line = malloc(256);

    
    int currentCal, maxCalories, elfNum, elfLargest;

    currentCal, maxCalories, elfNum, elfLargest = 0;
    
    


    
    textfile = fopen("input.txt","r");
    

    while(fgets(line, 10, textfile)) {
        if (atoi(line) == 0) {
            if (currentCal > maxCalories) {
                maxCalories = currentCal;
                elfLargest = elfNum;
            }
            currentCal = 0;
            elfNum++;
        } else {
            currentCal +=  atoi(line);
 
        }
        
    }
    printf("Elf %d is carrying %d calories of food.", elfLargest, maxCalories);
    

    fclose(textfile);
    

    return 0;
}