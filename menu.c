#include "menu.h"
#include <stdlib.h>
#include <stdio.h>

int your_choice()
{
    printf("\n\t Menu: \n\n");
    printf("%5d %-5s", 1, "Input data from the keyboard\n");
    printf("%5d %-5s", 2, "Input data from the file\n");
    printf("%5d %-5s", 3, "Display calculations\n");
    printf("%5d %-5s", 4, "Display impulse duration\n");
    printf("%5d %-5s", 5, "Save the results to file\n");
    printf("%5d %-5s", 6, "Save results for MAXIMA\n");
    printf("%5d %-5s", 7, "Load all from file\n");
    printf("%5d %-5s", EXITNUM, "Exit\n\n");
    int choice;
    printf("\t Your choice: ");
    scanf("%d%*c", &choice);
    while ((choice < 1)||(choice > EXITNUM))
    {
        printf("\a This value is out of range. \n Your choice: ");
        scanf("%d%*c", &choice);
    }
    system("cls");
    return choice;
}
