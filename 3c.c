#include <stdio.h>
#include <omp.h>
#include <limits.h>

int main()
{
    int arr[10];
    omp_set_num_threads(4);
    int max_val = 0.0;
    int min_val = INT_MAX;
    int i;
    printf("Enter 10 values");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
#pragma omp parallel for reduction(max \
                                   : max_val)
    for (i = 0; i < 10; i++)
    {
        printf("Thread id = %d and i = %d\n", omp_get_thread_num(), i);
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }
#pragma omp parallel for reduction(min \
                                   : min_val)
    for (i = 0; i < 10; i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    printf("\nmax_val = %d", max_val);
    printf("\nmin_val = %d\n", min_val);
}