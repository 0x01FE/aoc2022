#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE  *File;
    char *Line = malloc(256);

    int CurrentCal, MaxCalories, ElfNum, ElfLargest = 0;
    
    File = fopen("input.txt","r");
    

    while(fgets(Line, 10, File))
    {

        if (atoi(Line) == 0)
        {

            if (CurrentCal > MaxCalories)
            {
                MaxCalories = CurrentCal;
                ElfLargest = ElfNum;
            }

            CurrentCal = 0;
            ElfNum++;

        }
        else
            CurrentCal +=  atoi(Line);
 
        
    }

    printf("Elf %d is carrying %d calories of food.", ElfLargest, MaxCalories);
    
    fclose(File);
    
    return 0;
}