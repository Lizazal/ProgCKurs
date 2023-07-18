#include "calculate.h"
void create_time_array (int n, double tn, double tk, double time_array[])
{
    double dt=(tk-tn)/(n-1);
    int i=0;
    for (i=0; i<n; i++)
        time_array[i]=tn+i*dt;
}

void create_Uin_array (int n, double t1, double tn, double tk, double u1, const double time_array[], double Uin_array[])
{
    int i=0;
    for (i=0; i<n; i++)
    {
        if (time_array[i]<t1)
            Uin_array[i]=((time_array[i]-tn)*u1)/(t1-tn);
        else
            Uin_array[i]=(time_array[i]-t1)*(-u1)/(tk-t1)+u1;
    }
}

void create_Uout_array (int n, double Uin_array[], double Uout_array[], double u1, double u2, double u3, double u4)
{
    int i;
    for (i=0; i<n; i++)
    if (Uin_array[i]<=u2)
        Uout_array[i]=0;
    else if (Uin_array[i]<=u3)
        Uout_array[i]=(u4/(u3-u2))*(Uin_array[i]-u2);
        else
            Uout_array[i]=u4;
}

double impulse_duration (int n, double u[], double tn, double tk)
{
    int i;
    double dt, duration=0;
    dt=(tk-tn)/(n-1);
    double umax = u[0];
    for (i=0; i<n; i++)
        if (u[i]>umax)
            umax=u[i];
    double umid=0.5*umax;
    for (i=0; i<n; i++)
        if (u[i]>=umid)
            duration+=dt;
    return (duration);
}

void calculation (int n, double* input_duration, double* output_duration, double tn, double tk, double t1, double time_array[], double u1, double u2, double u3, double u4, double Uin_array[], double Uout_array[])
{
    create_time_array (n, tn, tk, time_array);
    create_Uin_array (n, t1, tn, tk, u1, time_array, Uin_array);
    create_Uout_array (n, Uin_array, Uout_array, u1, u2, u3, u4);
    *input_duration = impulse_duration(n, Uin_array, tn, tk);
    *output_duration = impulse_duration (n, Uout_array, tn, tk);
}
