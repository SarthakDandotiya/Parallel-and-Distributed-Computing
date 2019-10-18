#include <stdio.h>
#include <omp.h>
int main()
{
    int n, a[100], i;
    omp_set_num_threads(2);
    printf("Enter the no of terms uptill which you want to generate the Fibonnaci Series\n");
    scanf("%d", &n);
    a[0] = 0;
    a[1] = 1;
#pragma omp parallel
    {
#pragma omp single
        for (i = 2; i < n; i++)
        {
            a[i] = a[i - 2] + a[i - 1];
            printf("Id of thread involved in the computation of fib number %d is=%d\n", i + 1, omp_get_thread_num());
        }
#pragma omp barrier
#pragma omp single
        {
            printf("The series is:\n");
            for (i = 0; i < n; i++)
                printf("%d \t Id of the thread displaying this number is = %d\n", a[i], omp_get_thread_num());
        }
    }
    return 0;
}