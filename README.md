# 🚀 Multiplicacion de Matrices con OpenMP

Este proyecto implementa el **algoritmo clasico de multiplicacion de matrices** con **paralelismo usando OpenMP**, y automatiza pruebas de rendimiento midiendo tiempos de ejecucion en microsegundos.  

El objetivo es **analizar la escalabilidad**, calcular **speedup** y **eficiencia** al variar el tamaño de las matrices y el numero de hilos.

---

## 📌 Contenido
- `mmClasicaOpenMP.c` → Codigo en C con OpenMP para multiplicacion clasica.
- `Makefile` → Compilacion y ejecucion automatizada.
- `lanzador.pl` → Script para lanzar pruebas masivas y generar archivos `.dat`.
- `estadisticas_hilos.xlsx / .csv` → Resultados procesados (media y desviacion estandar).
- `README.md` → Este documento.

---

## 🛠️ Requisitos
- GCC con soporte OpenMP:
  ```bash
  sudo apt-get install build-essential
  ```
- Perl (para ejecutar el lanzador de pruebas).

---

## ⚙️ Compilacion
```bash
make
```

Esto genera el ejecutable `mmClasicaOpenMP`.

---

## ▶️ Ejecucion
Ejemplo con matriz **500x500**, **8 hilos** y **5 repeticiones**:
```bash
OMP_NUM_THREADS=8 ./mmClasicaOpenMP 500 5
```

---

## 🧪 Plan de pruebas
El proyecto contempla:
- **12 tamaños de matriz** (menores a 14K, ejemplo: `200, 300, 400, 600, 800, 1000, 1500, 2000, 3000, 4000, 6000, 8000`).
- **Numero de hilos**: `{1, 4, 8, 16, 20}`.
- **30 repeticiones** por combinacion.

Ejecutar todas las pruebas automaticamente:
```bash
make bench
```

Los resultados se guardan en `results/MM-<N>-Hilos-<T>.dat`.

---

## 📂 Formato de resultados
Cada archivo `.dat` contiene 30 tiempos de ejecucion (en microsegundos).  
Ejemplo de nombres:
```
mmClasicaOpenMP-200-Hilos-1.dat
mmClasicaOpenMP-200-Hilos-4.dat
mmClasicaOpenMP-200-Hilos-16.dat
```

---

## 📊 Analisis estadistico
A partir de los `.dat` se calculan:
- **Media** → tiempo promedio.
- **Desviacion estandar** → estabilidad de las mediciones.

Estos resultados estan en `estadisticas_hilos.xlsx` y `estadisticas_hilos.csv`, listos para graficar en Excel/Sheets.

---

## ⚡ Metricas de rendimiento
- **Speedup(N, T)**  
  ```
  Tiempo_1hilo(N) / Tiempo_Thilos(N)
  ```

- **Eficiencia(N, T)**  
  ```
  Speedup(N, T) / T
  ```

Estas metricas permiten evaluar la **escalabilidad** del algoritmo paralelo.

---

## 📈 Ejemplo de analisis
Para N = 200:

| Hilos | Media (µs) | Desv. Estandar (µs) | Speedup | Eficiencia |
|-------|------------|----------------------|---------|------------|
| 1     | 7506.7     | 1740.2              | 1.00    | 1.00       |
| 2     | 5118.2     | 995.7               | 1.47    | 0.74       |
| 4     | 3561.9     | 406.7               | 2.10    | 0.52       |
| 8     | 2144.8     | 198.7               | 3.50    | 0.44       |
| 16    | 1560.9     | 116.8               | 4.81    | 0.30       |
| 20    | 1789.2     | 330.9               | 4.19    | 0.21       |

---

## ✅ Conclusiones
- El paralelismo reduce significativamente los tiempos de ejecucion.  
- El speedup no escala linealmente: **la eficiencia disminuye** al aumentar los hilos.  
- Los resultados muestran el impacto de la **memoria y la sobrecarga de hilos** en la escalabilidad.  

---

✍️ **Autor:** Proyecto academico de paralelismo con OpenMP.  
📅 **Fecha:** 2025
