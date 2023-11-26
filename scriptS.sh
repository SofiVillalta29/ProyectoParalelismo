#!/bin/bash

gcc -fopenmp -o fibonacciS fibonacciS.c


> resultadosS.csv

for n in {10..30..5}
do
    ./fibonacciS $n >> resultadosS.csv
done
