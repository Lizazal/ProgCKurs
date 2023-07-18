#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include"output.h"
#define MAXLEN 100

void print_table (int n, double time_array[], double Uin_array[], double Uout_array[])
{
    int i;
    printf("%6s%15s%15s%15s", "N", "Time", "Uin", "Uout\n");
    for (i=0; i<n; i++)
            printf("%6i%15.3f%15.3f%15.3f\n", i+1, time_array[i], Uin_array[i], Uout_array[i]);
}

void show_impulse (int n, double tn, double tk, double t1, double u1, double u2, double u3, double u4, double input_duration, double output_duration)
{
    printf ("%2s%5s%9s%8s\n", "N", "tn", "tk", "t1");
    printf ("%3d%8.3f%8.3f%8.3f\n", n, tn, tk, t1);
    printf ("%4s%8s%8s%8s\n", "u1", "u2", "u3", "u4");
    printf ("%3.3f%8.3f%8.3f%8.3f\n\n", u1, u2, u3, u4);
    printf("%10s%25s\n","Input impulse duration","Output impulse duration");
    printf("%15.3f%19.3f\n", input_duration, output_duration);
}

void save_table (int n, double tn, double tk, double t1, double u1, double u2, double u3, double u4, double input_duration, double output_duration, double time_array[], double Uin_array[], double Uout_array[])
{
    int i;
    printf("Enter file name: ");
    char file_name[MAXLEN];
    scanf("%s", file_name);
    FILE* file;
       if((file=fopen(file_name,"w"))!=0)
       {
            fprintf (file, "%2s%5s%9s%8s%8s%8s%8s%8s\n", "N", "tn", "tk", "t1", "u1", "u2", "u3", "u4");
            fprintf (file, "%3d%8.3f%8.3f%8.3f%8.3f%8.3f%8.3f%8.3f\n", n, tn, tk, t1, u1, u2, u3, u4);
            fprintf(file,"%3s%17s%17s%17s\n", "N", "Time","U input","U output");
            for(i=0; i<n; i++)
                fprintf(file, "%6i%15.3f%15.3f%15.3f\n", i+1, time_array[i], Uin_array[i], Uout_array[i]);
            fprintf(file, "%25s%25s\n","Input impulse duration","Output impulse duration");
            fprintf(file, "%15.3f%19.3f\n\n", input_duration, output_duration);
            printf("Data was saved\n");
            fclose(file);
        }
            else
                printf("It is not possible to open the file.");
    pause();
    system("cls");
}

void file_maxima (int n, double time_array[], double Uin_array[], double Uout_array[])
{
    FILE *time_ar;
    time_ar = fopen ("time_array.txt", "w");
    FILE *Uin_ar;
    Uin_ar = fopen ("Uin_array.txt", "w");
    FILE *Uout_ar;
    Uout_ar = fopen ("Uout_array.txt", "w");
    int i;
    for(i=0;i<n;i++)
    {
        fprintf (time_ar, "%.3f\n", time_array[i]);
        fprintf (Uin_ar, "%.3f\n", Uin_array[i]);
        fprintf (Uout_ar, "%.3f\n", Uout_array[i]);
    }
    printf("Data was saved.\n");
    fclose(time_ar);
    fclose(Uin_ar);
    fclose(Uout_ar);
    pause();
    system("cls");
}
