import pandas as pd
import matplotlib.pyplot as plt

# Cargar datos
data = pd.read_csv('resultadosP.csv', names=['n', 'threads', 'time'])

# Limpieza de datos (eliminar filas con texto no deseado si es necesario)
data = data[data['time'].apply(lambda x: isinstance(x, float))]

# Graficar
for n in data['n'].unique():
    subset = data[data['n'] == n]
    plt.plot(subset['threads'], subset['time'], label=f'n={n}')

plt.xlabel('Número de Hilos')
plt.ylabel('Tiempo de Ejecución (s)')
plt.title('Rendimiento de Fibonacci Paralelo')
plt.legend()
plt.show()
