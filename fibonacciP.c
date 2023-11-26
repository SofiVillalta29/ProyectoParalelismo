#include <stdio.h>
#include <omp.h>

void fibonacci_parallel(int n, int *fib_series) {
    int i;
    fib_series[0] = 0;
    fib_series[1] = 1;

    #pragma omp parallel for
    for (i = 2; i <= n; i++) {
        // Cálculo paralelo con dependencias manejadas adecuadamente
        fib_series[i] = fib_series[i-1] + fib_series[i-2];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <n> <num_threads>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int num_threads = atoi(argv[2]);

    omp_set_num_threads(num_threads); // Establecer el número de hilos

    int fib_series[n+1];

    double start_time = omp_get_wtime();
    fibonacci_parallel(n, fib_series);
    double end_time = omp_get_wtime();

    printf("%d, %d, %f\n", n, num_threads, end_time - start_time); // Imprime n, num_threads y tiempo

    return 0;
}
