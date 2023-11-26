#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fibonacci_secuencial(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_secuencial(n - 1) + fibonacci_secuencial(n - 2);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    double start_time = omp_get_wtime();
    int resultado = fibonacci_secuencial(n);
    double end_time = omp_get_wtime();

    printf("%d, %f\n", n, end_time - start_time);

    return 0;
}
