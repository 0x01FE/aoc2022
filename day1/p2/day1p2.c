#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int FindSmallest(int Array[3])
{

    int SmallestNumberPosition = 0;
    int SmallestNumber = Array[0];

    for (int i = 1; i < 3; i++)
    {

        if (Array[i] < SmallestNumber)
        {
            SmallestNumber = Array[i];
            SmallestNumberPosition = i;
        }

    }

    return SmallestNumberPosition;
}


int main()
{

    FILE  *File;
    char *Line = malloc(256);

    int TopThree[3] = {0,0,0};
    int CurrentCal = 0;

    
    File = fopen("input.txt","r");
    
    while(fgets(Line, 10, File))
    {

        if (atoi(Line) == 0)
        {

            for (int i=0; i < 3; i++)
            {

                bool ZeroCheck = false;

                if (CurrentCal > TopThree[i])
                {
                    int SmallestPos = FindSmallest(TopThree);
                    TopThree[SmallestPos] = CurrentCal;
                    break;
                }

            }

            CurrentCal = 0;

        }
        else
            CurrentCal +=  atoi(Line);

    }
    
    int Total = 0;


    for (int i = 0; i < 3; i++)
        Total += TopThree[i];


    printf("Total of the top three elves: %d\n", Total);

    fclose(File);
    
    return 0;

}
