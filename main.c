#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "input.h"
#include "calculate.h"
#include "output.h"

int main()
{
    int n = 51;
    double tn = -10;
    double tk = 20;
    double t1 = 5;
    double u1 = 50;
    double u2 = 0;
    double u3 = 10;
    double u4 = 100;
    double input_duration;
    double output_duration;
    double time_array[MAX];
    double Uin_array[MAX];
    double Uout_array[MAX];
    int choice;
    while((choice=your_choice())!=EXITNUM)
    {
        switch(choice)
        {
        case 1:
            keyboard_input(&n, &tn, &tk, &t1, &u1, &u2, &u3, &u4);
        break;
        case 2:
            file_input(&n, &tn, &tk, &t1, &u1, &u2, &u3, &u4);
        break;
        case 3:
            calculation(n, &input_duration, &output_duration, tn, tk, t1, time_array, u1, u2, u3, u4, Uin_array, Uout_array);
            print_table(n, time_array, Uin_array, Uout_array);
            pause();
            system("cls");
        break;
        case 4:
            calculation (n, &input_duration, &output_duration, tn, tk, t1, time_array, u1, u2, u3, u4, Uin_array, Uout_array);
            show_impulse (n, tn, tk, t1, u1, u2, u3, u4, input_duration, output_duration);
            pause();
            system("cls");
        break;
        case 5:
            calculation(n, &input_duration, &output_duration, tn, tk, t1, time_array, u1, u2, u3, u4, Uin_array, Uout_array);
            save_table (n, tn, tk, t1, u1, u2, u3, u4, input_duration, output_duration, time_array, Uin_array, Uout_array);
        break;
        case 6:
            calculation (n, &input_duration, &output_duration, tn, tk, t1, time_array, u1, u2, u3, u4, Uin_array, Uout_array);
            file_maxima (n, time_array, Uin_array, Uout_array);
        break;
        case 7:
            load_file (&n, &tn, &tk, &t1, &u1, &u2, &u3, &u4, Uin_array, Uout_array, time_array, &input_duration, &output_duration);
        break;
        }
    }
        printf("\nGood bye\n");
    return 0;
}
