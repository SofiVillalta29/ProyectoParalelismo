import pandas as pd
import matplotlib.pyplot as plt

# Cargar datos secuenciales y eliminar duplicados
data_secuencial = pd.read_csv('resultadosS.csv', names=['n', 'time_secuencial']).drop_duplicates()

# Graficar resultados secuenciales
plt.plot(data_secuencial['n'], data_secuencial['time_secuencial'], label='Secuencial', marker='o')

plt.xlabel('Valor de n')
plt.ylabel('Tiempo de Ejecución (s)')
plt.title('Rendimiento de Fibonacci Secuencial')
plt.legend()
plt.grid(True)  # Agrega una cuadrícula para facilitar la lectura
plt.show()

