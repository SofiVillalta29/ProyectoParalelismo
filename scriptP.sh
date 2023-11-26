#!/bin/bash

# Compila el programa
gcc -fopenmp -o fibonacci fibonacciP.c

# Asegúrate de que el archivo de resultados esté vacío antes de empezar
> resultadosP.csv

# Ejecuta el programa con diferentes tamaños y números de hilos
for n in {10..30..5} # Prueba con n = 10, 15, 20, 25, 30
do
    for threads in {1..4} # Prueba con 1, 2, 3 y 4 hilos
    do
        ./fibonacci $n $threads >> resultadosP.csv
    done
done
