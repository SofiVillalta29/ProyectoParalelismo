#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fib(int n, int *memo) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    int i, j;

    #pragma omp task shared(i) firstprivate(n, memo)
    i = fib(n - 1, memo);

    #pragma omp task shared(j) firstprivate(n, memo)
    j = fib(n - 2, memo);

    #pragma omp taskwait
    return memo[n] = i + j;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <n> <num_threads>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    int *memo = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; ++i) {
        memo[i] = -1;
    }

    omp_set_num_threads(num_threads);

    double start_time = omp_get_wtime();
    int fibonacci_result;
    #pragma omp parallel
    {
        #pragma omp single
        fibonacci_result = fib(n, memo);
        //printf(" ");
    }
    
    double end_time = omp_get_wtime();

    free(memo);

    printf("%d,%d,%f\n", n, num_threads, end_time - start_time); 
    
    return 0;
}
