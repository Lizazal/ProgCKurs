#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

void keyboard_input(int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4);
void file_input(int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4);
void load_file (int *n, double *tn, double *tk, double *t1, double *u1, double *u2, double *u3, double *u4, double Uin_array[], double Uout_array[], double time_array[], double *input_duration, double *output_duration);

#endif // INPUT_H_INCLUDED
