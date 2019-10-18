#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i, n, tid;
    float a[100], b[100], sum;
    n = 12;
    for (i = 0; i < n; i++)
        a[i] = b[i] = i * 1.0;
    sum = 0.0;
#pragma omp parallel for reduction(+ \
                                   : sum)
    for (i = 0; i < n; i++)
    {
        tid = omp_get_thread_num();
        sum = sum + (a[i] * b[i]);
        printf(" tid= %d i=%d\n", tid, i);
    }
    printf(" Sum = %f\n", sum);
}