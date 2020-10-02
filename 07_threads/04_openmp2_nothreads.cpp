#include <stdio.h>
#include <math.h>

int main()
{
    const int N = 100000000;
    float sum = 0.0f;
    float *x = new float[N];
    float *z = new float[N];
    int i;

    /* populate x */
    for(i = 0; i < N; i++)
        x[i] = (i+1)*.002;

    /* map */
    for(i = 0; i < N; i++)
    {
        z[i] = sin(x[i]*x[i]);
    }

    /*do a sum*/
    for(i = 0; i < N; i++)
    {
        sum += z[i];
    }

    printf("%f\n", sum);
    return 0;
}