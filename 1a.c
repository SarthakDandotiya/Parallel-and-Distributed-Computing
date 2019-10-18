#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 8
#define NUM_THREADS 4

int main(int argc, char *argv[])
{

    int *a;
    int *b;
    int *c;

    int n = ARRAY_SIZE;
    int n_per_thread;
    int total_threads = NUM_THREADS;
    int i;

    // allocate spce for the arrays
    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * n);
    c = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        a[i] = i;
    }
    for (i = 0; i < n; i++)
    {
        b[i] = i;
    }

    omp_set_num_threads(total_threads);

    n_per_thread = n / total_threads;

#pragma omp parallel for shared(a, b, c) private(i) schedule(static, n_per_thread)
    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
        printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
    }

    printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}
