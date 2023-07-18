#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED

void create_time_array (int n, double tn, double tk, double time_array[]);
void create_Uin_array (int n, double t1, double tn, double tk, double u1, const double time_array[], double Uin_array[]);
void create_Uout_array (int n, double Uin_array[], double Uout_array[], double u1, double u2, double u3, double u4);
double impulse_duration (int n, double u[], double tn, double tk);
void calculation (int n, double* input_duration, double* output_duration, double tn, double tk, double t1, double time_array[], double u1, double u2, double u3, double u4, double Uin_array[], double Uout_array[]);
#endif // CALCULATE_H_INCLUDED
