#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
A-Z : 65-90 ; - 38
a-z : 97-122 ; - 96
*/
void print_line(char line[], int start, int end) {
    for (int i = start; i < end; i++) {
        printf("%c", line[i]);
    }
    printf("\n");
}

int main() {

    FILE *f;
    char *line = malloc(256);
    int total = 0;

    f = fopen("input.txt", "r");

    while (fgets(line, 256, f) != NULL) {
        int priority = 0;
        int size = strlen(line) - 1; // -1 because it includes the escape character
        int c1e = size/2; // compartment 1 end
        int c2s = c1e; //compartment 2 start
        char shared = ' ';


        print_line(line, 0, c1e);
        print_line(line, c2s, size);


        for (int i = 0; i < c1e; i++) {
            char current = line[i];

            for (int y = c2s; y < size; y++) {
                if (current == line[y]) {
                    shared = line[y];
                    break;
                }
            }

            if (shared != ' ') {
                break;
            }
        }

        printf("Shared Item: %c\n", shared);
        printf("\n");

        int n = (int) shared;

        if (n >= 65 && n <= 90) {
            priority += n-38;
        } else if (n >= 97 && n <= 122) {
            priority+= n-96;
        }

        total += priority;
    }

    printf("Total priority is %d\n", total);
    fclose(f);

    return 0;
}