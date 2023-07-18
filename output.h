#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

void print_table (int n, double time_array[], double Uin_array[], double Uout_array[]);
void show_impulse (int n, double tn, double tk, double t1, double u1, double u2, double u3, double u4, double input_duration, double output_duration);
void file_maxima (int n, double time_array[], double Uin_array[], double Uout_array[]);
void save_table (int n, double tn, double tk, double t1, double u1, double u2, double u3, double u4, double input_duration, double output_duration, double time_array[], double Uin_array[], double Uout_array[]);
#endif // OUTPUT_H_INCLUDED
