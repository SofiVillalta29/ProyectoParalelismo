import pandas as pd
import matplotlib.pyplot as plt

# Cargar datos y eliminar duplicados
data = pd.read_csv('resultadosP.csv', names=['n', 'threads', 'time']).drop_duplicates()

# Graficar
for n in data['n'].unique():
    subset = data[data['n'] == n]
    plt.plot(subset['threads'], subset['time'], label=f'n={n}', marker='o')

plt.xlabel('Número de Hilos')
plt.ylabel('Tiempo de Ejecución (s)')
plt.title('Rendimiento de Fibonacci Paralelo')
plt.legend()
plt.grid(True)  # Agrega una cuadrícula para facilitar la lectura
plt.show()
