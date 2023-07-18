#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#define MAXLEN 100

void keyboard_input (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4)
{
	printf("Enter n = ");
	scanf("%d", n);
	printf("Enter tn = ");
	scanf("%lf", tn);
	printf("Enter t1 = ");
	scanf("%lf", t1);
	printf("Enter tk = ");
	scanf("%lf", tk);
	printf("Enter u1 = ");
	scanf("%lf", u1);
	printf("Enter u2 = ");
	scanf("%lf", u2);
	printf("Enter u3 = ");
	scanf("%lf", u3);
	printf("Enter u4 = ");
	scanf("%lf", u4);
    if((*n>1)&&(*t1>*tn)&&(*tk>*t1)&&(*u2<*u3))
        printf("Data was read\n");
    else
        printf ("Data is not correct");
    pause();
    system("cls");
}

void file_input (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4)
{
    int i;
    printf("Enter file name: ");
    char file_name[MAXLEN];
	scanf ("%s", file_name);
	FILE* file;
    if((file=fopen(file_name,"r"))!=0)
    {
        fscanf(file,"%d%lf%lf%lf%lf%lf%lf%lf", n, tn, tk, t1, u1, u2, u3, u4);
        /*if((*n<1) || (*tn>*tk) || (*t1>*tk) || (*tn>*t1) || (*u2<*u3))
            printf("Data is not correct.\n");
        else*/
            printf("Data was read");
        fclose(file);
    }
    else
        printf("It is not possible to open the file\n");
    pause();
    system("cls");
}

void pause()
{
    printf("\nPress any key...\n");
    getch();
}

void load_fiile (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4, double Uin_array[],double Uout_array[], double time_array[], double *input_duration, double *output_duration)
{
    int i;
    printf("Enter file name: ");
    char file_name[MAXLEN];
	scanf ("%s", file_name);
	FILE* file;
	if((file=fopen(file_name,"r"))!=0)
    {
        char buf[MAXLEN];
        fgets (buf, sizeof(buf), file);
        fscanf (file, "%d%lf%lf%lf%lf%lf%lf%lf", n, tn, tk, t1, u1, u2, u3, u4);
        if((*n<1) || (*tn>*tk) || (*t1>*tk) || (*tn>*t1) || *u2>*u3)
            printf("Data is not correct.\n");
        else
        {
            fgets(buf, sizeof(buf), file);
            for (i = 0 ; i < *n ; i++)
                fscanf(file, "%*d%lf%lf%lf", time_array[i], Uin_array[i], Uout_array[i]);
            fgets(buf, sizeof(buf), file);
            fscanf(file, "%lf%lf", input_duration, output_duration);
            printf("Data was read");
        }
        fclose(file);
    }
    else
        printf("It is not possible to open the file\n");
    pause();
    system("cls");
}







/*void load_file (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4, double *Uin_array[],double *Uout_array[], double *time_array[], double *input_duration, double *output_duration)
{
    char buf[MAXLEN];
    printf("Enter file name: ");
    gets(buf);
	*n=21; *tn=-10; *tk=20; *t1=5; *u1=50; *u2=0;*u3=10;*u4=100;*input_duration=16.500; *output_duration=28.500;
	int i, k=-10, l=0;
	time_array[0]=-10; Uin_array[0]=0; Uout_array[0]=0;
	for (i=0; i<11; i++) {k+=1.5; time_array[i]=k; l+=5; Uin_array[i]=l;}
	for (i=11; i<21; i++) {k+=1.5; time_array[i]=k; l-=5; Uin_array[i]=l;}
    for (i=2; i<19; i++) Uout_array[i]=100;
	Uout_array[1]=50; Uout_array[19]=50; Uout_array[20]=0;
    printf("Data was read\n");
    pause();
    system("cls");
}
void load_filem (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4, double *Uin_array[],double *Uout_array[], double *time_array[], double *input_duration, double *output_duration)
{
    char buf[MAXLEN];
    printf("Enter file name: ");
    gets(buf);
	*n=21; *tn=-10; *tk=20; *t1=5; *u1=1; *u2=0;*u3=10;*u4=100;*input_duration=16.500; *output_duration=16.500;
	int i, k=-10, l=0, z=0;
	time_array[0]=-10; Uin_array[0]=0; Uout_array[0]=0;
	for (i=0; i<11; i++) {k+=1.5; time_array[i]=k; l+=0.1; Uin_array[i]=l; z+=1; Uout_array[i]=z;}
	for (i=11; i<21; i++) {k+=1.5; time_array[i]=k; l-=0.1; Uin_array[i]=l; z+=-1; Uout_array[i]=z;}
    printf("Data was read\n");
    pause();
    system("cls");
}
void load_fileb (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4, double *Uin_array[],double *Uout_array[], double *time_array[], double *input_duration, double *output_duration)
{
    char buf[MAXLEN];
    printf("Enter file name: ");
    gets(buf);
	*n=21; *tn=-10; *tk=20; *t1=5; *u1=20; *u2=0;*u3=10;*u4=100;*input_duration=16.500; *output_duration=22.500;
	int i, k=-10, l=0;
	time_array[0]=-10; Uin_array[0]=0; Uout_array[0]=0;
	for (i=0; i<11; i++) {k+=1.5; time_array[i]=k; l+=2; Uin_array[i]=l;}
	for (i=11; i<21; i++) {k+=1.5; time_array[i]=k; l-=2; Uin_array[i]=l;}
    for (i=5; i<16; i++) Uout_array[i]=100;
	Uout_array[1]=Uout_array[19]=20;Uout_array[2]=Uout_array[18]=40;Uout_array[3]=Uout_array[17]=60;Uout_array[4]=Uout_array[16]=80;
    printf("Data was read\n");
    pause();
    system("cls");
}



*/



int skip_until_line_startswith_digit(FILE* file)
{
    int expect_digit = 1;
    for (int c; (c = fgetc(file)) != EOF; )
    {
        switch (c)
        {
            case '\n':
                expect_digit = 1;
                break;
            case ' ':
            case '\t':
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            if (expect_digit)
            {
                if (ungetc(c, file) == EOF)
                    return -2;
            return 0;
            }
            break;
            default:
            expect_digit = 0;
        }
    }
    return feof(file) ? -1 : -2;
}

void load_file (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4, double Uin_array[],double Uout_array[], double time_array[], double *input_duration, double *output_duration)
{
    int i;
    printf("Enter file name: ");
    char file_name[MAXLEN];
	scanf ("%s", file_name);
    FILE* file = stdin;
	if((file=fopen(file_name,"r"))!=0)

    {
    if (skip_until_line_startswith_digit(file) < 0)
        exit(EXIT_FAILURE);
    errno = 0;
    if (fscanf(file, "%d%lf%lf%lf%lf%lf%lf%lf", n, tn, tk, t1, u1, u2, u3, u4) != 8)
    {
        if (errno) perror("N   tn       tk      t1      u1      u2      u3      u4");
        exit(EXIT_FAILURE);
    }
        printf("Data was read");
        fclose(file);
    }
    else
        printf("It is not possible to open the file\n");
    pause();
    system("cls");
}
